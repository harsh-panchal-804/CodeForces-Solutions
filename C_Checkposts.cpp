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
int n;
stack<int> stk;
vector<bool> visited;
vector<vector<int>> adj(1e5+10,vector<int>());
vector<vector<int>> radj(1e5+10,vector<int>());
void dfs1(int n){
    visited[n]=true;
    for(auto child: adj[n]){
        if(!visited[child]){
            dfs1(child);
        }
    }
    stk.push(n);
}
void dfs2(int node,vector<int>& vec){
    visited[node]=true;
    vec.push_back(node);
    for(auto child: radj[node]){
        if(!visited[child]){
            dfs2(child,vec);
        }
    }
}



void solve(){
   
    cin>>n;
    vector<int> cost(n+1);
    for(int i=1;i<=n;i++)cin>>cost[i];
    int m;
    cin>>m;
    while(m--){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        radj[v].push_back(u);
    }
    visited.assign(n+1,false);
    for(int i=1;i<=n;i++)if(!visited[i])dfs1(i);
    visited.assign(n+1,false);
    ll fans=0;
    ll ways=1;
    while(!stk.empty()){
        int node=stk.top();
        stk.pop();
        if(!visited[node]){
            vector<int> comps;
            dfs2(node,comps);
            ll mn=LONG_LONG_MAX;
            ll count=0;
            for(auto c: comps){
                if(cost[c]<mn){
                    mn=cost[c];
                    count=1;
                }
                else if(cost[c]==mn){
                    count++;
                }
            }
            fans +=  mn;
            ways =(ways *1ll*  count)%mod;
        }
    }
    cout<<fans<<" "<<ways<<"\n";


    
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
