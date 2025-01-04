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
bool isValid(pair<int,int>&a ,pair<int,int>&b){
    int dist_sqr= (a.first-b.first) * (a.first-b.first) + (a.second-b.second) *(a.second-b.second);
    int dist_root= sqrt(dist_sqr);
    return !(dist_root*dist_root==dist_sqr);
}
map<pair<int,int>,vector<pair<int,int>>> mp;
map<pair<int,int>,vector<pair<int,int>>> rmp;
vector<pair<int,int>> points;
map<pair<int,int>,bool> visited;
stack<pair<int,int>> stk;
void dfs(pair<int,int>&node){
    if(visited[node])return;
    visited[node]=true;
    for(auto child: mp[node]){
        dfs(child);
    }
    stk.push(node);
}
void dfs2(pair<int,int>&node,vector<pair<int,int>>& comp){
    if(visited[node])return;
    visited[node]=true;
    comp.push_back(node);
    for(auto  &child :rmp[node]){
        dfs(child);
    }
}

void solve(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            points.push_back({i,j});
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(isValid(points[i],points[j])){
                mp[points[i]].push_back(points[j]);
                rmp[points[j]].push_back(points[i]);
            }
        }
    }
    for(int i=0;i<points.size();i++)dfs(points[i]);
    vector<pair<int,int>> fcomps;
    int ans=0;
    visited.clear();
    while(!stk.empty()){
        pair<int,int> & node=stk.top();
        stk.pop();
        if(visited[node])continue;
        vector<pair<int,int>> comps;
        dfs2(node,comps);
        if(comps.size()>ans){
            ans=comps.size();
            fcomps=comps;
        }
    }
    cout<<ans<<"\n";
    for(auto i : fcomps){
        cout<<i.first<<" "<<i.second<<"\n";
    }
    
    
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
