#include <bits/stdc++.h>
#pragma GCC optimize("O3") // O3 or we may time out :(
#define ll long long int
using namespace std;  

//class based PolyHashing

#define ll long long int
/*
   101 =>1e9(32 bits)
   111 => 111000
             101
          111101
*/  

/**
 * PolyHash technique:
 * - Uses polynomial rolling hash with two large primes (mod1, mod2) 
 *   to reduce collisions (double hashing).
 * - Precomputes prefix hashes and power arrays in O(n).
 * - Substring hash (l, r) can be extracted in O(1) using:
 *     hash(l,r) = (prefix[r] - prefix[l-1] * base^(r-l+1)) % mod
 * - Combines two hashes into a 64-bit value (x1 | (x2 << 32)) for uniqueness.
 * - Useful for string matching, palindrome check, LCP/LCS, and prefix-suffix problems.
 */
     

class PolyHash {
    public: 
    vector<ll> h1,h2,p1,p2;
    ll mod1=1e9+7,mod2=1e9+9,base=1e8+7;
    PolyHash(string s) {
        int n = s.length();
        h1.resize(n+1),h2.resize(n+1),p1.resize(n+1,1),p2.resize(n+1,1);

        for(int i=1; i<=n; i++) { //base power arrays
            p1[i] = (p1[i-1] * base)%mod1;
            p2[i] = (p2[i-1] * base)%mod2;
        }
        
        /*
           Hash(s) => (s[0] * base^(n-1) + s[1]*base^(n-2) + s[2]*base^(n-3) + ..... + s[n-1]*base^0) % M
        */
        for(int i=0; i<n; i++) { //prefix hashes
           int val = s[i]-'a';
           h1[i+1] = (((h1[i] + val)%mod1)*base)%mod1;
           h2[i+1] = (((h2[i] + val)%mod2)*base)%mod2;
        }
    }
     /*. 
           a b a b
          hash at 4th(1 based) index => a*(base^4) + b*(base^3) + a*(base^2) + b*(base^1) 
          hash at 2th index => a*(base^2) + b*(base^1) 
    */
    ll get_hash(int l, int r) { //(l,r) => (1 based indexing)
         ll x1 = (h1[r] - (h1[l-1] * p1[r-l+1])%mod1 + mod1)%mod1;
         ll x2 = (h2[r] - (h2[l-1] * p2[r-l+1])%mod2 + mod2)%mod2;
         return (x1 | (x2<<32)); //(double hashing) : mutliplying with 2^32 to x2 and or with x1 to make it ll(64) bits
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
 

 
