#include <bits/stdc++.h>
#pragma GCC optimize("O3") // O3 or we may time out :(
#define ll long long int
using namespace std;  

//class based PolyHashing

class PolyHash {
    public: 
    vector<ll> h1,h2,pow1,pow2;
    ll mod1 = 1e9+7, mod2 = 1e9+9, BASE = 91138233;

    PolyHash(vector<int> arr) {
        int n = arr.size();
        h1.resize(n+1, 0), h2.resize(n+1, 0), pow1.resize(n+1, 1), pow2.resize(n+1, 1); 

        for(int i=1; i<n; i++) {
            pow1[i] = (pow1[i-1] * BASE)%mod1;
            pow2[i] = (pow2[i-1] * BASE)%mod2;
        }
        for(int i=0; i<n; i++) { 
            h1[i+1] = ((h1[i] + arr[i])%mod1 * BASE)%mod1;
            h2[i+1] = ((h2[i] + arr[i])%mod2 * BASE)%mod2;
        }
    }
    ll get_hash(int l, int r){
        ll x1 = (h1[r] - (h1[l] * pow1[r-l])%mod1 + mod1)%mod1;
        ll x2= (h2[r] - (h2[l] * pow2[r-l])%mod2 + mod2)%mod2;

        return x1 | (x2<<32);
    } 
};


int solve()
{   
    string s;
    cin>>s;

    int n = s.length();

        
    // For storing powers of the base and hashes for the string
    const long long int MOD1 = 1000000007;
    const long long int MOD2 = 1000000009;
    const long long int BASE = 91138233;
    vector<long long int> pow1(n + 1, 1), pow2(n + 1, 1);
    vector<long long int> h1(n + 1, 0), h2(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        pow1[i] = (pow1[i - 1] * BASE) % MOD1;
        pow2[i] = (pow2[i - 1] * BASE) % MOD2;
    }

    // Computing hashes of prefixes of the string
    for (int i = 0; i < n; ++i) {
        long long int val = s[i] - 'a' + 1;
        h1[i + 1] = (h1[i] * BASE + val) % MOD1;
        h2[i + 1] = (h2[i] * BASE + val) % MOD2;
    }

    // Function to get the hash of a substring [l, r]
    auto get_hash = [&](int l, int r) {
        long long int x1 = (h1[r] + MOD1 - (h1[l] * pow1[r - l]) % MOD1) % MOD1;
        long long int x2 = (h2[r] + MOD2 - (h2[l] * pow2[r - l]) % MOD2) % MOD2;
        return (x1 << 32) | x2;
    };

    cout<<get_hash(0,n)<<endl; //[0...n-1]  1 lesser
    
    return 0;
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
 

 