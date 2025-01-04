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

void _prll(int t) { cerr << t; }
void _prll(ll t) { cerr << t; }
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



void solve(){
    ll n,k;
    cin>>n>>k;
    vector<ll> vec(n);
    for(ll i=0;i<n;i++)cin>>vec[i];
    sort(all(vec));
    vector<ll> prefix(n+1,0);
    for(ll i=1;i<n+1;i++){
        prefix[i]=prefix[i-1]+vec[i-1];
    }
    ll ans=0;
    ll ele=-1;
    for(ll i=0;i<n;i++){
        ll low=0;
        ll high=i;
        ll tans=-1;
        while(low<=high){
            ll mid=(low+high)/2;
            ll c=(i-mid+1ll)*vec[i] - (prefix[i+1]-prefix[mid]);
            if(c<=k){
                tans= i-mid+1;
                high=mid-1;
                if(tans>ans){
                    ans=tans;
                    ele=vec[i];
                }
            }
            else{
                low=mid+1;
            }
        }
    }
    cout<<ans<<" "<<ele<<"\n";
    
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
