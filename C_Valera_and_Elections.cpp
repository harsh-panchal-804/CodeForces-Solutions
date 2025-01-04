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
vector<vector<pair<int,int>>> vec;
int n;
vector<int> d;
vector<int> white;
void dfs(int node,int par=-1){
    d[node]=0;
    if(white[node]){
        d[node]+=1;
    }
    for(auto child:vec[node]){
        if(child.first==par)continue;
        dfs(child.first,node);
        d[node]+=d[child.first];
    }
}


void solve(){
    cin>>n;
    d.resize(n);
    vec.resize(n);
    white.resize(n);
    for(int i=0;i<n-1;i++){
        int u,v,t;
        cin>>u>>v>>t;
        u--;
        v--;
        if(t==2){
            white[u]=1;
            white[v]=1;
        }
        vec[u].push_back({v,t});
        vec[v].push_back({u,t});
    }
    dfs(0);
    vector<int> ans;
    for(int i=0;i<n;i++){
        if(d[i]==1){
            ans.push_back(i+1);
        }
    }
    cout<<ans.size()<<"\n";
    for(auto i : ans){
        cout<<i<<" ";
    }
    cout<<"\n";

    
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("Error.txt", "w", stderr);
    #endif
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int test=1;
    // cin>>test;
    while(test--){
         solve();
    }
    
    return 0;
}
