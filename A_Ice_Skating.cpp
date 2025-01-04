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
void dfs(vector<vector<int>> & graph,int node,vector<bool>& visited){
    visited[node]=true;
    for(auto children:graph[node]){
        if(visited[children])continue;
        visited[children]=true;
        dfs(graph,children,visited);
    }
}


void solve(){
    int n;
    cin>>n;
    vector<pair<int,int>> vec;
    for(int i=0;i<n;i++){
        int u,v;
        cin>>u>>v;
        vec.push_back({u,v});
    }
    
    vector<vector<int>> graph(n+1,vector<int>(n+1));

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(vec[i].first==vec[j].first || vec[i].second == vec[j].second){
               graph[i].push_back(j);
               graph[j].push_back(i);
            }
        }
    }
    vector<bool> visited(n+1,false);
    int rem=0;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            rem++;
            dfs(graph,i,visited);
        }
    }
    cout<<rem-1<<"\n";
   
    
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
