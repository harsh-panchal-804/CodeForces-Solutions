#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
const long long mod = 1e9 + 7;
#define INF (1LL << 60)
#define inf (1 << 30)
#define all(x) (x).begin(), (x).end()

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " "; _prll(x); cerr << endl;
#else
#define debug(x)
#endif

void _prll(ll t) { cerr << t; }
void _prll(int t) { cerr << t; }
void _prll(string t) { cerr << t; }
void _prll(char t) { cerr << t; }
void _prll(lld t) { cerr << t; }
void _prll(double t) { cerr << t; }
void _prll(ull t) { cerr << t; }

template <class T, class V> void _prll(pair <T, V> p);
template <class T> void _prll(vector <T> v);
template <class T> void _prll(set <T> v);

template <class T, class V> void _prll(map <T, V> v);
template <class T> void _prll(multiset <T> v);

template <class T, class V> void _prll(pair <T, V> p) {
    cerr << "{"; _prll(p.first); cerr << ","; _prll(p.second); cerr << "}";
}
template <class T> void _prll(vector <T> v) {
    cerr << "[ "; for (T i : v) {_prll(i); cerr << " ";} cerr << "]";
}
template <class T> void _prll(set <T> v) {
    cerr << "[ "; for (T i : v) {_prll(i); cerr << " ";} cerr << "]";
}
template <class T> void _prll(multiset <T> v) {
    cerr << "[ "; for (T i : v) {_prll(i); cerr << " ";} cerr << "]";
}
template <class T, class V> void _prll(map <T, V> v) {
    cerr << "[ "; for (auto i : v) {_prll(i); cerr << " ";} cerr << "]";
}
bool check(ll val,ll a,ll b){
    while (val > 0) {
        if (val % 10 == a || val % 10 == b) {
            val /= 10;
        } else return false;
    }
    return true;
}
ll fact[(ll)1e6+100];
void init_fact(){
    fact[0] = 1;
    for(int i = 1; i < (1e6 +100); i++) {
        fact[i] = (fact[i-1] * i);
        fact[i] %= mod;
    }
}
ll binExp(ll a,ll b,ll mod){
    ll ans=1;
    while(b){
        if(b&1){
            ans=(ans*a)%mod;
        }
        a=(a*a)%mod;
        b/=2;
    }
    return ans;
}
ll getC(ll n,ll r){
    ll ans=fact[n];
   
    ll div=(fact[n-r]*1ll*fact[r])%mod;
    ll fdiv=binExp(div,mod-2,mod);
    return (ans*1ll*fdiv)%mod;
}

void solve(){
    ll a,b,n;
    cin>>a>>b>>n;
    init_fact();
    ll ans=0;
    for(ll i=0;i<=n;i++){
        ll sum= a*i +(n-i)*b;
        if(check(sum,a,b)){
            ans += getC(n,i);
            ans%=mod;
        }
    }
    cout<<ans<<"\n";
    
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("Error.txt", "w", stderr);
    #endif
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    ll test=1;
    // cin>>test;
    while(test--){
         solve();
    }
    
    return 0;
}
