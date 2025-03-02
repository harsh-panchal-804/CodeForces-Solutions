#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

typedef long double lld;
const ll mod = 1e9 + 7;
#define INF (1LL << 60)
#define inf (1 << 30)
#define all(x) (x).begin(), (x).end()

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(lld t) { cerr << t; }
void _print(double t) { cerr << t; }


template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);

template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);

template <class T, class V> void _print(pair <T, V> p) {
    cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";
}
template <class T> void _print(vector <T> v) {
    cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";
}
template <class T> void _print(set <T> v) {
    cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";
}
template <class T> void _print(multiset <T> v) {
    cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";
}
template <class T, class V> void _print(map <T, V> v) {
    cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";
}


/// bs over predicate?
void solve(){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<ll> a(n);
    ll max_penalty = 0;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        max_penalty = max(max_penalty, a[i]);
    }
    auto feasible = [&](ll P) -> bool {
        int ops = 0;
        int i = 0;
        while(i < n){
                if(a[i] > P && s[i]=='R'){
                    i++;
                    continue;
                }
                bool has_forced_blue = false;
                while(i < n && !(a[i] > P && s[i]=='R')){
                    if(a[i] > P && s[i]=='B'){
                        has_forced_blue = true;
                    }
                    i++;
                }
                if(has_forced_blue) ops++;  
            }
            return ops <= k;
        };
        ll lo = 0, hi = max_penalty, ans = hi;
        while(lo <= hi){
            ll mid = lo + (hi - lo) / 2;
            if(feasible(mid)){
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
    cout << ans << "\n";
    
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("Error.txt", "w", stderr);
    #endif
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int test=1;
    cin>>test;
    while(test--){
         solve();
    }
    
    return 0;
}
