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
void _print(ull t) { cerr << t; }

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



void solve(){
    ll n,x,k;
    cin>>n>>x>>k;
    string s;
    cin>>s;
    ll time_elapsed=0;
    bool vis_zero=false;
    for(auto i : s){
        if(i=='L'){
            x--;
        }
        else{
            x++;
        }
        time_elapsed++;
        if(x==0){
            vis_zero=true;
            break;
        }
    }
    if(!vis_zero){
        cout<<0<<"\n";
        return;
    }
    ll time_rem=k-time_elapsed;
    ll cycle_time=0;
    bool cycle_found=false;
    x=0;
    for(auto i : s){
        if(i=='L')x--;
        else x++;
        cycle_time++;
        if(x==0){
            cycle_found=true;
            break;
        }
    }
    if(cycle_found){
        cout<<time_rem/ cycle_time +1<<"\n";
    }
    else{
        cout<<1<<"\n";
    }
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
