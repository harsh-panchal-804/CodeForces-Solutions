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
vector<pair<int,int>> dirs={{-1,0},{1,0},{0,1},{0,-1}};
void dfs(int x,int y,vector<vector<int>>& vis,vector<vector<int>>& graph,vector<int> &comps,int clr){
    if(x<0 || y< 0 || x>=graph.size() || y>=graph[0].size() || vis[x][y]!=-1 || graph[x][y]!=clr)return;
    vis[x][y]=1;
    comps.push_back(graph[x][y]);
    for(auto dir : dirs){
        int nx=x+ dir.first;
        int ny=y+ dir.second;
        dfs(nx,ny,vis,graph,comps,clr);
    }

}
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> vec(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>vec[i][j];
        }
    }
    vector<vector<int>> comps;
    vector<vector<int>> vis(n,vector<int>(m,-1));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vis[i][j]==-1){
                vector<int> cmp;
                dfs(i,j,vis,vec,cmp,vec[i][j]);
                comps.push_back(cmp);
            }
        }
    }
    int max_comp=-1;
    for(int i=0;i<comps.size();i++){
        max_comp=max(max_comp,(int)comps[i].size());
    }
    debug(comps);
    debug(max_comp);
    //// break same color component if they are reachable

    
    

    
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
