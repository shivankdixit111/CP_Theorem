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
#define mod 1000000007
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


const int prime = 37;
vector<vector<long long> > hashes; 
void PreComputeHash (const string& s) {
    int n = s.length();
    hashes.clear();
    hashes.resize(n);
    
    for (int i = 0; i < n; i ++) {
        long long pwr = prime;
        long long prefix = 0; 
        
        for (int j = i; j < n; j ++) {
            long long val = (pwr * s[j]) % mod;
            prefix = (prefix + val) % mod;
            
            hashes[i].push_back (prefix);
            pwr = (pwr * prime) % mod;
        }
    }
} 

bool isEqual (int l1, int r1, int l2, int r2) {
    int len = (r2 - l2 + 1); 
    return (hashes[l1][len-1] == hashes[l2][len-1]);
} 


// -------------   when n = 1e3  -------


 
int solve()
{   
    string s = "abcabcdef";
    PreComputeHash(s);
    
    cout<< isEqual(0, 2, 3, 5) <<endl;  //1
    cout<< isEqual(0, 3, 4, 5) <<endl;  //0
    
    ret;
}
 
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    // long long t;
    // cin >> t;
    // while (t--)
 
        solve();
 
    return 0;
}