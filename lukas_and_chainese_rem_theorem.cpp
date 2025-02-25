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



int fact2[100001], fact5[100001];
    int power(int x, int y,int mod){
        int ans = 1;
        while(y) {
            if(y&1) ans = (ans *1LL* x)%mod;
            x = (x *1LL* x)%mod;
            y = y>>1;
        }
        return ans;
    }
    void pre(){
       fact2[0] = 1, fact5[0] = 1;
       for(int i=1;i<100001;i++) {
          fact2[i] = (fact2[i-1] *1LL * i)%2;
          fact5[i] = (fact5[i-1] *1LL * i)%5;
       }
    }
    int ncr_5(int n, int r, int mod) {
        if(r > n) return 0;
        int dividend = fact5[n];
        int divisor = (fact5[r] *1LL* fact5[n-r]); 
        int ans = (dividend *1LL* power(divisor, mod-2, mod))%mod;
        return ans;
    }
    int ncr_2(int n, int r, int mod) {
        if(r > n) return 0;
        int dividend = fact2[n];
        int divisor = (fact2[r] *1LL* fact2[n-r])%mod; 
        int ans = (dividend *1LL* power(divisor, mod-2, mod))%mod;
        return ans;
    }
    int ncr_5_lukas(int n, int r, int mod) {
        int ans = 1;
        while(n or r) {
            int new_n = n % mod, new_r = r % mod;
            ans = (ans *1LL* ncr_5(new_n, new_r, mod))%mod;
            n = n/mod;
            r = r/mod;
        }
        return ans;
    }
    int ncr_2_lukas(int n, int r, int mod) {
        int ans = 1;
        while(n or r) {
            int new_n = n % mod, new_r = r % mod;
            ans = (ans *1LL* ncr_2(new_n, new_r, mod))%mod;
            n = n/mod;
            r = r/mod;
        }
        return ans;
    }
    int fun(int n, int r, int x) { 
        //prime factors of x = [2, 5]
       int ncr_mod_5 = ncr_5_lukas(n, r, 5);
       int ncr_mod_2 = ncr_2_lukas(n, r, 2); 

       //chainese remainer theorem
       for(int i=0;i<10;i++) {
         if((i % 2 == ncr_mod_2) and (i % 5 == ncr_mod_5)) {
            return i;
         }
       }
       return 0;
    }

   int solve()
   {   
       int n,r;
       cin>>n>>r;

       pre();
      
     /*?
       calculating ncr % x  where x is not a prime
        break x into prime factors
        lets say x = 10  prime factors = [2, 5]
        calc ncr%2 and ncr%5 with lukas theorem and 
        then apply chainese reaminder theorem
      */
      /* Example:
        5 0 = 1 % 10 = 1
        5 1 = 5 % 10 = 5
        5 2 = 10 % 10 = 0
        5 3 = 10 % 10 = 0
        5 4 = 5 % 10 = 5
        5 5 = 1 % 10 = 1
     */

      cout<< fun(n, r, 10) <<endl;
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