import * as vscode from 'vscode';
import * as http from 'http';
import * as https from 'https';

export class ContextSidebarProvider implements vscode.WebviewViewProvider {
    public static readonly viewType = 'contextSyncView';
    private _view?: vscode.WebviewView;

    constructor(
        private readonly _extensionUri: vscode.Uri,
    ) { }

    public resolveWebviewView(
        webviewView: vscode.WebviewView,
        context: vscode.WebviewViewResolveContext,
        _token: vscode.CancellationToken,
    ) {
        this._view = webviewView;
        webviewView.webview.options = {
            enableScripts: true,
            localResourceRoots: [this._extensionUri]
        };

        // Initial "Welcome" State
        webviewView.webview.html = this._getHtmlForWebview();

        // Handle messages from webview
        webviewView.webview.onDidReceiveMessage(message => {
            switch (message.type) {
                case 'connectGithub':
                    vscode.commands.executeCommand('contextsync.connectGithub');
                    break;
                case 'openGraph':
                    vscode.window.showInformationMessage("Opening Full Graph Explorer...");
                    break;
                case 'copy':
                    vscode.env.clipboard.writeText(message.text);
                    vscode.window.showInformationMessage('Copied to clipboard!');
                    break;
            }
        });
    }

    // --- Public UI Methods ---

    public showLoading(text: string = "Analyzing...") {
        this._view?.webview.postMessage({ type: 'showLoading', value: text });
    }

    public updateGitHubStatus(isConnected: boolean) {
        this._view?.webview.postMessage({ type: 'updateGithub', value: isConnected });
    }

    // --- Backend Logic (Your HTTP Requests) ---

    public explainCode(codeSnippet: string, filePath: string, lineNumbers: string) {
        this._makeRequest('/explain', { code_snippet: codeSnippet, file_path: filePath, line_numbers: lineNumbers }, 
            (data) => {
                // Success: Format the Gemini response as a "Verdict" card
                // Assuming data.markdown contains the text
                const response = JSON.parse(data);
                this._view?.webview.postMessage({ 
                    type: 'addVerdict', 
                    value: response.markdown || response.text // Adjust based on your Python API response
                });
            }
        );
    }

    public fetchContextObjects(codeSnippet: string, filePath: string, lineNumbers: string) {
        this._makeRequest('/context/retrieve', { code_snippet: codeSnippet, file_path: filePath, line_numbers: lineNumbers }, 
            (data) => {
                // Success: Format the Chroma response as "Evidence" cards
                const response = JSON.parse(data);
                // Expecting response to be an array of objects
                this._view?.webview.postMessage({ 
                    type: 'addEvidence', 
                    value: response 
                });
            }
        );
    }

    // Helper to reuse HTTP logic
    private _makeRequest(path: string, payload: any, onSuccess: (data: string) => void) {
        const config = vscode.workspace.getConfiguration('contextsync');
        const apiBaseUrl = config.get<string>('apiBaseUrl') || 'http://127.0.0.1:8000';
        
        let hostname = '127.0.0.1';
        let port = 8000;
        let protocol = 'http:';

        try {
            const url = new URL(apiBaseUrl);
            hostname = url.hostname;
            port = parseInt(url.port) || (url.protocol === 'https:' ? 443 : 80);
            protocol = url.protocol;
        } catch (e) { }

        const postData = JSON.stringify(payload);
        const options = {
            hostname, port, path, method: 'POST',
            headers: {
                'Content-Type': 'application/json',
                'Content-Length': Buffer.byteLength(postData)
            }
        };

        const requestModule = protocol === 'https:' ? https : http;
        const req = requestModule.request(options, (res) => {
            let data = '';
            res.on('data', chunk => data += chunk);
            res.on('end', () => {
                if (res.statusCode === 200) {
                    try {
                        onSuccess(data);
                    } catch (e) {
                        this._showError("Failed to parse server response.");
                    }
                } else {
                    this._showError(`Server Error: ${res.statusCode}`);
                }
            });
        });

        req.on('error', (e) => this._showError("Context Engine unreachable."));
        req.write(postData);
        req.end();
    }

    private _showError(msg: string) {
        this._view?.webview.postMessage({ type: 'statusUpdate', value: `❌ ${msg}` });
    }

    // --- HTML / CSS / JS Generation ---

    private _getHtmlForWebview() {
        return `<!DOCTYPE html>
        <html lang="en">
        <head>
            <meta charset="UTF-8">
            <meta name="viewport" content="width=device-width, initial-scale=1.0">
            <style>
                :root { 
                    --font-family: var(--vscode-font-family); 
                    --fg: var(--vscode-editor-foreground);
                    --bg: var(--vscode-editor-background);
                    --border: var(--vscode-widget-border);
                }
                body { font-family: var(--font-family); padding: 15px; color: var(--fg); background: var(--bg); }
                
                /* Layout */
                .header { display: flex; justify-content: space-between; align-items: center; margin-bottom: 15px; }
                .title { font-weight: bold; font-size: 1.1em; display: flex; align-items: center; gap: 6px; }
                .status-dot { height: 8px; width: 8px; background-color: #28a745; border-radius: 50%; }
                
                /* Buttons */
                button { cursor: pointer; border: none; border-radius: 3px; padding: 4px 10px; font-family: inherit; }
                .view-toggle { background: var(--vscode-button-secondaryBackground); color: var(--vscode-button-secondaryForeground); opacity: 0.7; }
                .view-toggle.active { opacity: 1; background: var(--vscode-button-background); color: var(--vscode-button-foreground); }
                
                .github-btn { 
                    width: 100%; padding: 8px; margin-bottom: 20px; 
                    background: #24292e; color: white; display: flex; align-items: center; justify-content: center; gap: 8px; 
                }
                .github-btn:hover { opacity: 0.9; }
                .github-btn.connected { background: #28a745; cursor: default; }

                /* Cards */
                .card { 
                    background: var(--vscode-sideBar-background); 
                    border: 1px solid var(--border); 
                    padding: 12px; margin-bottom: 12px; border-radius: 4px; 
                    border-left: 3px solid transparent;
                    box-shadow: 0 2px 4px rgba(0,0,0,0.05);
                }
                .card.verdict { border-left-color: #f1c40f; } /* Yellow for Warning/Insight */
                .card.evidence { border-left-color: #3498db; } /* Blue for Context */
                
                .card h3 { margin: 0 0 8px 0; font-size: 0.95em; text-transform: uppercase; letter-spacing: 0.5px; opacity: 0.7; }
                .card-content { font-size: 0.9em; line-height: 1.5; }

                /* Evidence Items */
                .evidence-item { display: flex; justify-content: space-between; align-items: center; padding: 6px 0; border-bottom: 1px solid var(--border); }
                .evidence-item:last-child { border-bottom: none; }
                .tag { font-size: 0.75em; background: var(--vscode-badge-background); color: var(--vscode-badge-foreground); padding: 2px 6px; border-radius: 10px; }

                /* Loading */
                #loader { text-align: center; color: var(--vscode-descriptionForeground); margin-top: 30px; display: none; }
                .spinner { border: 3px solid var(--vscode-widget-shadow); border-top: 3px solid var(--vscode-progressBar-background); border-radius: 50%; width: 20px; height: 20px; animation: spin 1s linear infinite; margin: 0 auto 10px auto; }
                @keyframes spin { 0% { transform: rotate(0deg); } 100% { transform: rotate(360deg); } }

                /* Graph Placeholder */
                #graph-view { display: none; height: 300px; border: 1px dashed var(--border); align-items: center; justify-content: center; color: var(--vscode-descriptionForeground); flex-direction: column; text-align: center; padding: 20px; }
            </style>
        </head>
        <body>
            
            <div class="header">
                <div class="title"><span class="status-dot"></span>ContextSync</div>
                <div>
                    <button class="view-toggle active" id="btn-list">List</button>
                    <button class="view-toggle" id="btn-graph">Graph</button>
                </div>
            </div>

            <button class="github-btn" id="github-connect">
                <svg width="16" height="16" viewBox="0 0 16 16" fill="currentColor"><path d="M8 0C3.58 0 0 3.58 0 8c0 3.54 2.29 6.53 5.47 7.59.4.07.55-.17.55-.38 0-.19-.01-.82-.01-1.49-2.01.37-2.53-.49-2.69-.94-.09-.23-.48-.94-.82-1.13-.28-.15-.68-.52-.01-.53.63-.01 1.08.58 1.23.82.72 1.21 1.87.87 2.33.66.07-.52.28-.87.51-1.07-1.78-.2-3.64-.89-3.64-3.95 0-.87.31-1.59.82-2.15-.08-.2-.36-1.02.08-2.12 0 0 .67-.21 2.2.82.64-.18 1.32-.27 2-.27.68 0 1.36.09 2 .27 1.53-1.04 2.2-.82 2.2-.82.44 1.1.16 1.92.08 2.12.51.56.82 1.27.82 2.15 0 3.07-1.87 3.75-3.65 3.95.29.25.54.73.54 1.48 0 1.07-.01 1.93-.01 2.2 0 .21.15.46.55.38A8.013 8.013 0 0016 8c0-4.42-3.58-8-8-8z"/></svg>
                Connect GitHub
            </button>

            <div id="loader">
                <div class="spinner"></div>
                <span id="loader-text">Analyzing context...</span>
            </div>

            <div id="list-view">
                <div id="verdict-container"></div>
                <div id="evidence-container"></div>
                
                <div id="welcome-hint" style="opacity: 0.5; text-align: center; margin-top: 40px;">
                    Select code and run <b>ContextSync: Explain</b><br>to see risk analysis here.
                </div>
            </div>

            <div id="graph-view">
                <div style="font-size: 30px; margin-bottom: 10px;">🕸️</div>
                <p>Interactive Context Graph</p>
                <button class="view-toggle" onclick="vscode.postMessage({type: 'openGraph'})" style="margin-top:10px;">⤢ Full Screen</button>
            </div>

            <script src="https://cdn.jsdelivr.net/npm/markdown-it@13.0.1/dist/markdown-it.min.js"></script>
            <script>
                const vscode = acquireVsCodeApi();
                const md = window.markdownit();

                // Elements
                const loader = document.getElementById('loader');
                const loaderText = document.getElementById('loader-text');
                const verdictContainer = document.getElementById('verdict-container');
                const evidenceContainer = document.getElementById('evidence-container');
                const welcomeHint = document.getElementById('welcome-hint');
                const btnGithub = document.getElementById('github-connect');
                
                // State Logic
                document.getElementById('btn-list').addEventListener('click', () => switchView('list'));
                document.getElementById('btn-graph').addEventListener('click', () => switchView('graph'));
                
                function switchView(view) {
                    document.getElementById('list-view').style.display = view === 'list' ? 'block' : 'none';
                    document.getElementById('graph-view').style.display = view === 'graph' ? 'flex' : 'none';
                    document.getElementById('btn-list').classList.toggle('active', view === 'list');
                    document.getElementById('btn-graph').classList.toggle('active', view === 'graph');
                }

                // GitHub Click
                btnGithub.addEventListener('click', () => {
                    vscode.postMessage({ type: 'connectGithub' });
                });

                // Message Handler
                window.addEventListener('message', event => {
                    const msg = event.data;
                    
                    switch (msg.type) {
                        case 'showLoading':
                            loader.style.display = 'block';
                            loaderText.innerText = msg.value;
                            welcomeHint.style.display = 'none';
                            verdictContainer.innerHTML = '';
                            evidenceContainer.innerHTML = '';
                            break;
                            
                        case 'addVerdict':
                            loader.style.display = 'none';
                            const vDiv = document.createElement('div');
                            vDiv.className = 'card verdict';
                            vDiv.innerHTML = '<h3>⚠️ Risk Analysis</h3><div class="card-content">' + md.render(msg.value) + '</div>';
                            verdictContainer.appendChild(vDiv);
                            break;
                            
                        case 'addEvidence':
                            loader.style.display = 'none';
                            const listHtml = msg.value.map(item => \`
                                <div class="evidence-item">
                                    <div style="display:flex; flex-direction:column; gap:2px;">
                                        <span style="font-weight:600">\${item.source}</span>
                                        <span style="font-size:0.85em; opacity:0.8">\${item.title_or_user || item.title}</span>
                                    </div>
                                    <span class="tag">95% Match</span>
                                </div>
                            \`).join('');
                            
                            const eDiv = document.createElement('div');
                            eDiv.className = 'card evidence';
                            eDiv.innerHTML = '<h3>🔍 Historical Context</h3>' + listHtml;
                            evidenceContainer.appendChild(eDiv);
                            break;

                        case 'updateGithub':
                            if (msg.value) {
                                btnGithub.innerHTML = '✓ GitHub Connected';
                                btnGithub.classList.add('connected');
                            }
                            break;
                            
                        case 'statusUpdate':
                            loaderText.innerText = msg.value;
                            break;
                    }
                });
            </script>
        </body>
        </html>`;
    }
}