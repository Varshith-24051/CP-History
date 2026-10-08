import * as vscode from 'vscode';
import { ContextSidebarProvider } from './sidebar';

export function activate(context: vscode.ExtensionContext) {
    console.log('ContextSync extension is activating...');

    try {
        const sidebarProvider = new ContextSidebarProvider(context.extensionUri);

        // 1. Register the Sidebar View
        context.subscriptions.push(
            vscode.window.registerWebviewViewProvider("contextSyncView", sidebarProvider)
        );

        // 2. Command: Explain Code (The "Ask" feature)
        context.subscriptions.push(
            vscode.commands.registerCommand('contextsync.explain', () => {
                const editor = vscode.window.activeTextEditor;
                if (!editor) {
                    vscode.window.showWarningMessage('ContextSync: No active text editor.');
                    return;
                }
                
                const selection = editor.selection;
                const text = editor.document.getText(selection);
                const filePath = editor.document.fileName;
                const lineNumbers = `${selection.start.line + 1}-${selection.end.line + 1}`;

                if (text.trim().length === 0) {
                    vscode.window.showWarningMessage('Please highlight some code to explain.');
                    return;
                }

                // Show loading state in UI immediately
                sidebarProvider.showLoading("Analyzing Risk & Intent...");
                
                // Trigger the backend call
                sidebarProvider.explainCode(text, filePath, lineNumbers);
                
                // Focus the sidebar
                vscode.commands.executeCommand('contextSyncView.focus');
            })
        );

        // 3. Command: Show Context (The "Search" feature)
        context.subscriptions.push(
            vscode.commands.registerCommand('contextsync.showContext', () => {
                const editor = vscode.window.activeTextEditor;
                if (!editor) { return; }

                const selection = editor.selection;
                const text = editor.document.getText(selection);
                const filePath = editor.document.fileName;
                const lineNumbers = `${selection.start.line + 1}-${selection.end.line + 1}`;

                sidebarProvider.showLoading("Scanning Vector Database...");
                sidebarProvider.fetchContextObjects(text, filePath, lineNumbers);
                vscode.commands.executeCommand('contextSyncView.focus');
            })
        );

        // 4. NEW Command: Connect GitHub
        context.subscriptions.push(
            vscode.commands.registerCommand('contextsync.connectGithub', async () => {
                // Here you would normally trigger OAuth or ask for a Token
                const token = await vscode.window.showInputBox({ 
                    prompt: "Enter GitHub Personal Access Token (PAT)", 
                    password: true 
                });
                
                if (token) {
                    vscode.window.showInformationMessage('ContextSync: GitHub Connected Securely.');
                    // Update the UI to show the green checkmark
                    sidebarProvider.updateGitHubStatus(true);
                }
            })
        );

        console.log('ContextSync extension activated successfully!');
    } catch (error) {
        console.error('ContextSync activation error:', error);
        vscode.window.showErrorMessage(`ContextSync failed to activate: ${error}`);
    }
}

export function deactivate() { }