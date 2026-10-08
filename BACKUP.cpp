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

//24//12//2025//
//To minimize the sum of absolute distances to a point, choose the median position.
