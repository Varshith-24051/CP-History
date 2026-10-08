/*---------------------------------------------------------LEARNINGS-------------------------------------------------------------*/
/*19/10/2025
Get the value of the minimum element*/
int x = *min_element(v.begin(), v.end());
//Get the index of the minimum element
auto it = min_element(v.begin(), v.end());
int index = distance(v.begin(), it);


/*-------------------------------------------------------------------------------------------------------------------------------*/
/*20/10/2025
Check if a substring exists in a string*/
if (s.find("aba") != string::npos) {
}
/*-------------------------------------------------------------------------------------------------------------------------------*/
/*23/10/2025 10:45 am
There is something called LLONG_INT , and llabs() also for long long int*/
/*28/10/25*/
getline(cin >> ws, name);
/*29/10/25*/
(S == T ? "YES" : "NO");
// this check 2 then skipps all the even numbers;
for (int64_t p = 2; p * p <= n; p += p % 2 + 1)
// for all gcd of a array just loop
X= gcd(X, a[i]);
//CPP MACRO for loop
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
/*07/11/2025*/
//To check if an array is sorted
if( is_sorted(v.begin(),v.end()))

//That blinking “|” thing is officially called the text cursor or insertion point — but most people just call it the caret//
//10/11/2025//
/* to check if all the elements are same just sort it and find the last nad the fist element if same then yes else no*/
//11/11/2025//
#define fi first
#define se second
#define yes cout << "YES\n"
#define no cout << "NO\n"
//for diffrernt cases ECE 0011, 1010 type 
int dx[4] = {-1, 1, -1, 1}, dy[4] = {-1, -1, 1, 1};

//12/11/2025//
//prefix-sum trick and multiple in takes;
for (int i=1; i<=n; i++) cin >> a[i], pre[i]=pre[i-1]+a[i];

//this is to swap '0' and '1'--------------------------
for(int i = 0 ; i< N ; i++){
    s[i]='0'+'1'-s[i];
}
//01/12/2025//
//LEFT MEDIAN 
(n+1)/2 
//RIGHT MEDIAN
(n/2)+1
//10/12/2025//
string(size_t n, char c)
//17/12/2025//
//this is for the sum of first n natural numbers but it can also be used for the continous k to max n possible arrays permutations where 
y=n-k+1;
ans += y * (y + 1) / 2;
//18/12/2025//
rotate(v.begin()+l,v.begin()+l+1,v.end());
//this rotates the array from l to end by 1 to the left 
for (int i = 0; i < v.size(); i++) {
            ans[v[i]] = v[(i + 1) % v.size()] + 1;
        }
//shifting by one position to the right
//sliding window its like imagine i want k of my things to be in one order then ill just use my window as k and then check if there are amny impositors best na
//24/12/2025//
int compl = count_if(v.begin(), v.end(),[&](int x){ return x < a; });

int compr = count_if(v.begin(), v.end(),[&](int x){ return x > a; });

//24/12//2025//
//To minimize the sum of absolute distances to a point, choose the median position.
val += abs(a[pos] - a[i]) - abs(pos - i);

//25/12/2025//
//so beautfull trick 
int dif = -1;
        if (i > 0)
            dif = max(dif, a[i] - pre[i - 1]);

        if (i < n - 1)
            dif = max(dif, a[i] - pre[i + 1]);

        ans += dif + 1;


//26/12/2025//
//Function to find the first occurrence of a substring in a string
int pos = haystack.find(needle);
return (pos == string::npos) ? -1 : pos;


// no.of.array() , if you want to divide it like 171 242 and you haveb like no.of  7 = 12  and no.of 1 is like 14 and you want to make them into an array such a wasy that the addgesents form a numebr of same then the formula is : 
ans += 1 + max(0, abs(x - y) - 1);

//04/03/2026//
// yh well for a matrix if u arwe planning to divide and calculate then for the for loops u need to check wether the n/2 and (n+1)/2 == n 
// by that i mean like i and j iterations limits must be equal to n so it matrhimitically garenties its iteration througth all the elements
i < (n+1)/2
j < n/2
or
i < n/2
j < (n+1)/2

// both works...E. Mirror Grid

int minIdx = min_element(a.begin(), a.end()) - a.begin();
int maxIdx = max_element(a.begin(), a.end()) - a.begin(); 

//new topic fewqueancy for pairs ? 
n(n-1)/2 // think of it as n matrix and then removed x,y elements i.e x==y and 
         // then 2 diffrenet lower and upper triangle as it is same we need unique we do /2 
         //---> nC2
// __count leading zeros long long  
__builtin_clzll(x);

//if only clz = int 
__builtin_clz(x);


// number of pairs in an array for all i< j 
n(n-1)/2 //---> nC2

// Pre-requisites: Sort 'a' and calculate Prefix Sums
sort(a.begin(), a.end());
for(int i = 1; i < n; i++) a[i] += a[i-1];

long long ans = 0;
long long cur_day = 0;

//_________________________________________________________________________//
// Iterate backwards from max items to 1 item
for (int i = n - 1; i >= 0; i--) {
    long long k = i + 1;
    
    // Check if affordable at the current point in time
    if (a[i] + (cur_day * k) <= x) {
        
        // 1. Calculate the absolute limit (The Fast-Forward)
        long long max_day = (x - a[i]) / k;
        
        // 2. Count days in this 'era'
        long long valid_days = max_day - cur_day + 1;
        
        // 3. Update total items
        ans += (valid_days * k);
        
        // 4. Warp to the day after the era ends
        cur_day = max_day + 1;
    }
}//________________________________________________________________________//
// for choices in DP but only for OR operations binary only
 ans = (rec(i - 1, sum) | rec(i - 1, sum - a[i]));

 //count the bits of a number 
  if (a[i] & (1 << bit)) {
                count[bit]++;
            }

            a.erase(unique(a.begin(), a.end()), a.end());

//----------// that 1-color too make that thiing change for red/ black tree 
           
            void dfs(int node, int color, vector<vector<int>>& adj, vector<int>& visited) {
	visited[node]++;
	if (color == 1)
		red++;
	else
		white++;
	
	for (int neighbor : adj[node]) {
		if (!visited[neighbor]) {
			dfs(neighbor, 1 - color, adj, visited);
		}
	}
}
//------------//
//12/05/2026//
if(it != s.end()) {
   // for all *it 
} else if(it != a.begin()) {
   // for *(it -1);
}

/*Never use nested $O(N^2)$ loops for Manhattan distances. Split $X$ and $Y$ coordinates into separate lists and sort them ascending.
 Loop through each element and add v[i] * (2 * i - n + 1) to your total sum.*/
 // well this comes when you break down the modulo of the distances and then 
 //solve it comes to +3x +x -x -3x (diff x v1,2,3,4 values ) like that ish when you add 

 //abs distance to median ----------
 int target = p[mid] - mid + i;

    // 2. How far is that from where it is right now?
    total_moves += abs(p[i] - target);

//

//0/06/2026//
        // not bad Modulo optimization: subtraction is significantly faster than '%'
        if (next_dp[multiple] >= MOD) next_dp[multiple] -= MOD;

        //input errors 
        if (!(cin >> n >> k)) return;

        // std::move transfers ownership without copying, keeping memory operations O(1)
        dp = move(next_dp); 

        //algo: Counting Inversions or Fenwick Tree (Binary Indexed Tree)  
//23/06/2026
        //Linear Diophantine Equations find karo something gcd ish eq ish solving 
---
// instead of ther for loop 
 c1 = count(s.begin(), s.end(), '+');

 //
    for (int i = 0; i < (1LL << 12); i++) {
        int sum = 0; 
        int count = 0; 
        
        for (int j = 0; j < 12; j++) {
            if ((i >> j) & 1) {
                sum += facts[j];
                count++;
            }
        }
    }        

//29/06/2026
// 2. Lambda function for reading & Run-Length Encoding on the fly
    auto read_blocks = [](int len) {
        vector<int> runs;
        int r = 0;
        for (int i = 0, x; i < len; ++i) {
            cin >> x;
            if (x) r++;
            else if (r) runs.push_back(exchange(r, 0)); // 3. The exchange trick
        }
        if (r) runs.push_back(r);
        return runs;
    };
//30/06/2026

//pow with mod best 
int powm(int x, int n) {
		// Fast exponentiation: returns x^n mod M
		x %= M;
		if (n == 0) return 1;
		else if (n == 1) return x;

		int p = powm(x * x, n / 2); // square base while halving exponent
		if (n % 2) return p * x % M; // if n is odd, multiply once more by x
		else return p;
}


//But if you pass greater<int> into a heap or priority_queue, 
//it flips the logic and puts the smallest element at the top.

// trick to print 
cout << ans[i] << " \n"[i == n - 1];

//Sweep Line Algorithm edu round of 27 TWO TVs
// Process events in chronological order
    while (!pq.empty()) {
        auto [time, change] = pq.top();
        pq.pop();

        active_tvs += change;

        if (active_tvs > 2) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";


//10/07/2026//
//nice short way to end else case in macro case (1781C)
string out(n, ' ');
for (int i = 0; i < n; i++) {
    (mp[s[i]] > 0) ? (out[i] = s[i], mp[s[i]]--) : void();
}

//11/07/2026//
/*1 << uc is a raw binary shift. It takes exactly 1 CPU cycle.
pow(2, uc) is a complex math algorithm. It takes roughly 50 to 100 CPU cycles.
If you use pow() to calculate your loop boundary, you are burning dozens of CPU cycles for absolutely no reason.*/


//12/06/2026//
// Minimalist, contiguous-memory DSU struct
struct DSU {
    vector<int> p;
    DSU(int n) : p(n) { iota(p.begin(), p.end(), 0); }
    int get(int x) { return x == p[x] ? x : p[x] = get(p[x]); }
    void unite(int x, int y) { p[get(x)] = get(y); }
};
//VVVVVIMP//

//std::iota is just a super-fast C++ standard library function that fills an array with increasing numbers.
//Instead of writing this:
for(int i = 0; i < n; i++) {
    p[i] = i;
}