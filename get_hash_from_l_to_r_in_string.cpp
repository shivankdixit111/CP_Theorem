#define ll long long int
     
class PolyHash {
   public:
     vector<ll> h1,h2,rh1,rh2,p1,p2;
     ll mod1=1e9+7, mod2=1e9+9, base=1e8+7;
     PolyHash(string s) {
        int n = s.length();
        h1.resize(n+1,0), h2.resize(n+1,0);
        rh1.resize(n+1, 0), rh2.resize(n+1, 0);
        p1.resize(n+1, 1), p2.resize(n+1, 1);

        for(int i=1; i<=n; i++) {
            p1[i] = (p1[i-1] * base)%mod1; 
            p2[i] = (p2[i-1] * base)%mod2; 
        }

        for(int i=0; i<n; i++) {
            ll val = s[i]-'a'+1;
            h1[i+1] = ((h1[i] + val) * base) % mod1;
            h2[i+1] = ((h2[i] + val) * base) % mod2;
        }
        for(int i=n-1; i>=0; i--) {
            ll val = s[i]-'a'+1;
            rh1[i] = ((rh1[i+1] + val) * base) % mod1;
            rh2[i] = ((rh2[i+1] + val) * base) % mod2;
        }
     }

       ll get_hash(int l, int r) {
            r++;
            ll x1 = (h1[r] - (h1[l] * p1[r-l])%mod1 + mod1) % mod1; 
            ll x2 = (h2[r] - (h2[l] * p2[r-l])%mod2 + mod2) % mod2;
            return (x1 | (x2 << 32));
        }

        ll get_hash_rev(int l, int r) { 
            r++;
            ll x1 = (rh1[l] - (rh1[r] * p1[r-l])%mod1 + mod1) % mod1; 
            ll x2 = (rh2[l] - (rh2[r] * p2[r-l])%mod2 + mod2) % mod2;
            return (x1 | (x2 << 32));
        }

        bool isPal(int l, int r) {
            return get_hash(l,r) == get_hash_rev(l,r);
        }
};


 
 
 
 

 
