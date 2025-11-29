#include <bits/stdc++.h> 
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


/* -------------------- PolyHashing (comparing two strings in O(1)) -----------------*/
#define MAXLEN 100010

constexpr uint64_t modd = (1ULL << 61) - 1;

const uint64_t seed = chrono::system_clock::now().time_since_epoch().count();
const uint64_t base = mt19937_64(seed)() % (modd / 3) + (modd / 3);

uint64_t base_pow[MAXLEN];

int64_t modmul(uint64_t a, uint64_t b){
    uint64_t l1 = (uint32_t)a, h1 = a >> 32, l2 = (uint32_t)b, h2 = b >> 32;
    uint64_t l = l1 * l2, m = l1 * h2 + l2 * h1, h = h1 * h2;
    uint64_t res = (l & modd) + (l >> 61) + (h << 3) + (m >> 29) + (m << 35 >> 3) + 1;
    res = (res & modd) + (res >> 61);
    res = (res & modd) + (res >> 61);
    return res - 1;
}

void init(){
    base_pow[0] = 1;
    for (int i = 1; i < MAXLEN; i++){
        base_pow[i] = modmul(base_pow[i - 1], base);
    }
}

struct PolyHash{
    /// Remove suff vector and usage if reverse hash is not required for more speed
    vector<int64_t> pref, suff;

    PolyHash() {}

    template <typename T>
    PolyHash(const vector<T>& ar){
        if (!base_pow[0]) init();

        int n = ar.size();
        assert(n < MAXLEN);
        pref.resize(n + 3, 0);
        suff.resize(n + 3, 0);

        for (int i = 1; i <= n; i++){
            pref[i] = modmul(pref[i - 1], base) + ar[i - 1] + 997;
            if (pref[i] >= mod) pref[i] -= mod;
        }

         for (int i = n; i >0; i--){
            suff[i] = modmul(suff[i+1], base) + ar[i - 1] + 997;
            if (suff[i] >= mod) suff[i] -= mod;
        }

    }

    PolyHash(const char* str)
        : PolyHash(vector<char> (str, str + strlen(str))) {}
   
    PolyHash(const std::string& str)
        : PolyHash(vector<char>(str.begin(), str.end())) {}

    uint64_t get_hash(int l, int r){
        int64_t h = pref[r + 1] - modmul(base_pow[r - l + 1], pref[l]);
        return h < 0 ? h + mod : h;
    }

    uint64_t rev_hash(int l, int r){
        int64_t h = suff[l +1] - modmul(base_pow[r - l + 1], suff[r+2]);
        return h < 0 ? h + mod : h;
    }
}; 
 
 
 
int solve()
{   
    string s1 = "abcdef";
    string s2 = "abcdef";
    string revs1 = "fedcba";

    PolyHash ph1 = PolyHash(s1);
    PolyHash ph2 = PolyHash(s2);

    int hash1 = ph1.get_hash(0,s1.length()-1);
    int hash2 = ph2.get_hash(0,s2.length()-1);

    //s1 and s2 are equal or not
    if(hash1 == hash2) {
        cout<<"equal"<<endl;
    } else {
        cout<<"Not equal"<<endl;
    }

    int rhash1 = ph1.rev_hash(0,revs1.length()-1);
     //s1 and revs1 are equal or not
    if(hash1 == rhash1) {
        cout<<"palindrome"<<endl;
    } else {
        cout<<"not palindrome"<<endl;
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
