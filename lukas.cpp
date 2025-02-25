#include <bits/stdc++.h>
#pragma GCC optimize("O3") // O3 or we may time out :(
using namespace std;  
 
// lc
#define vi vector<int>
#define vvii vector<vi>
#define vpii vector<pair<int,int>>
#define vs vector<string>
#define mii map<int, int>
#define umii unordered_map<int, int>
#define minpq(a) priority_queue<a,vi,greater<a>> pq
#define maxpq(a) priority_queue<a> pq 
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define sall(x) sort(x.begin(), x.end());
#define rall(x) sort(x.rbegin(), x.rend())
#define pb push_back 
#define in insert
#define ff first
#define ss second
#define rep(i, a, b) for (int i = a; i < b; i++)
#define all(x) x.begin(), x.end()
#define sall(x) sort(x.begin(), x.end());
#define rall(x) sort(x.rbegin(), x.rend())
#define MAX(x) *max_element(x.begin(), x.end())
#define MIN(x) *min_element(x.begin(), x.end())
#define SUM(X) accumulate(X.begin(), X.end(), 0LL)
#define rev(a) reverse(a.begin(), a.end());
 
#define int long long 
#define pii pair<int, int>
#define mod1 998244353  
#define sei set<int>
#define ses set<string>
#define ues unordered_set<string> 
#define MEM(x, y) memset(x, y, sizeof(x))
#define binone(x) __builtin_popcountll(x) 
const int N = 1e5 + 7;
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define ret return 0
#define endl '\n' // remove for interactives

    int fact[100001];
    int power(int x, int y, int mod){
        int ans = 1;
        while(y) {
            if(y&1) ans = (ans *1LL* x)%mod;
            x = (x *1LL* x)%mod;
            y = y>>1;
        }
        return ans;
    }
    void pre(int mod){
       fact[0] = 1;
       for(int i=1;i<100001;i++) {
          fact[i] = (fact[i-1] *1LL * i)%mod; 
       }
    } 
    int ncr(int n, int r, int mod) {
        if(r > n) return 0;
        int dividend = fact[n];
        int divisor = (fact[r] *1LL* fact[n-r])%mod; 
        int ans = (dividend *1LL* power(divisor, mod-2, mod))%mod;
        return ans;
    }
    int ncr_lukas(int n, int r, int mod) {
        int ans = 1;
        while(n or r) {
            int new_n = n % mod, new_r = r % mod;
            ans = (ans *1LL* ncr(new_n, new_r, mod))%mod;
            n = n/mod;
            r = r/mod;
        }
        return ans;
    } 


   int solve()
   {   
       int n,r;
       cin>>n>>r;

       pre(7);

    //    normal ncr 
    //    5 5 = 1 % 7 = 1
    //    6 3 = 20 % 7 = 6
    //    6 2 = 1 % 7 = 6


       cout<< ncr_lukas(n, r, 7) <<endl; 


   
       ret;
   }
    
   signed main()
   {
       ios_base::sync_with_stdio(false);
       cin.tie(nullptr);
       cout.tie(nullptr);
    
       long long t;
       cin >> t;
       while (t--)
    
           solve();
    
       return 0;
   }