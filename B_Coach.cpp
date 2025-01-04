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

void dfs(int i,vector<int>& visited,vector<int> &comps,vector<vector<int>>& adj){
    if(visited[i])return;
    visited[i]=1;
    comps.push_back(i);
    for(auto child: adj[i]){
        if(!visited[child]){
            dfs(child,visited,comps,adj);
        }
    }
}

void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<vector<int>> team_1,team_2,team_3;
    vector<int> visited(n+1,0);
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            vector<int> comps;
            dfs(i,visited,comps,adj);
            if(comps.size()>3){
                cout<<-1<<"\n";
                return;
            }
            if(comps.size()==3)team_3.push_back(comps);
            if(comps.size()==2)team_2.push_back(comps);
            if(comps.size()==1)team_1.push_back(comps);
        }
    }
    if(team_2.size()>team_1.size()){
        cout<<-1<<'\n';
        return;
    }
    for(int i=0;i<team_2.size();i++){
        team_2[i].push_back(team_1.back()[0]);
        team_1.pop_back();
        team_3.push_back(team_2[i]);
    }
    if(team_1.size()%3!=0){
        cout<<-1<<"\n";
        return;
    }
    for(int i=0;i<team_1.size();i+=3){
        auto j={team_1[i][0],team_1[i+1][0],team_1[i+2][0]};
        team_3.push_back(j);
    }
    for(auto & i: team_3){
        for(auto & ch: i){
            cout<<ch<<" ";
        }
        cout<<"\n";
    }
    
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("Error.txt", "w", stderr);
    #endif

    int test=1;
    // cin>>test;
    while(test--){
         solve();
    }
    
    return 0;
}
