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

class fTree{
    public: 
    vector<int> bit;
    int n;
    fTree(int n) {
        bit.resize(n+1,0);
        this->n = n;
    }
    void update(int idx, int val) {
        idx++;  // 1 based indexing
        while(idx<=n) {
            bit[idx] += val;
            idx += idx & (-idx);
        }
    }

    int sum(int idx) {
        idx++;  // 1 based indexing
        int s = 0;
        while(idx>0) {
            s += bit[idx];
            idx -= idx & (-idx);
        }
        return s;
    } 

    int getSum(int l, int r) {
        int s = sum(r) - (l ? sum(l-1) : 0);
        return s;
    }
};
 
 
int solve()
{   
    int n;
    cin>>n;
    vi arr(n);
    rep(i,0,n) cin>>arr[i];

    fTree f = fTree(n);

    rep(i,0,n) {
        f.update(i, arr[i]);
    }

    int q;
    cin>>q;

    while(q--) {
        int type;
        cin>>type;
        if(type==1) {
            int l,r;
            cin>>l>>r;

            //get sum
            cout<< f.getSum(l,r) <<endl;
        } else {
            int idx,val;
            cin>>idx>>val;

            f.update(idx, val - arr[idx]);  //update the value with the difference 
            arr[idx] = val;
        }
    }

    
    
    
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