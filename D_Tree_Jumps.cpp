#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(long double t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(unsigned long long t) { cerr << t; }

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T, class V> void _print(pair <T, V> p) {
    cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";
}
template <class T> void _print(vector <T> v) {
    cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]";
}
template <class T> void _print(set <T> v) {
    cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]";
}
template <class T> void _print(multiset <T> v) {
    cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]";
}
template <class T, class V> void _print(map <T, V> v) {
    cerr << "[ "; for (auto i : v) { _print(i); cerr << " "; } cerr << "]";
}


map<int,int> node_lvl;

void solve(){
    node_lvl.clear();
    ll n;
    cin >> n;
    vector<ll> parent(n+1);
    vector<vector<ll>> graph(n+1);
    parent[1] = 1;
    for(ll i = 2; i <= n; i++){
        ll x;
        cin>>x;
        graph[x].push_back(i);
        graph[i].push_back(x);
        parent[i]=x;
    }
    // debug(graph);
    map<ll,vector<ll>> lvl_map;
    queue<pair<ll,ll>> queue;
    queue.push({1,1});
    vector<bool> visited(n+1, false);
    while(!queue.empty()){
        ll node=queue.front().first;
        ll lvl=queue.front().second;
        queue.pop();
        node_lvl[node]=lvl;
        lvl_map[lvl].push_back(node);
        visited[node]=true;
        for(auto child : graph[node]){
            if(!visited[child]){
                queue.push({child, lvl + 1});
            }
        }
    }
    // debug(lvl_map);
    ll max_level = 0;
    for(auto &p : lvl_map){
        max_level = max(max_level, p.first);
    }
    ll ans = 1; 
    if(lvl_map.count(2))
        ans = (ans + lvl_map[2].size()) % mod;
    for (ll d = 2; d < max_level; d++){
        if(lvl_map.count(d + 1)){ /// dont count if neighbour
            ans =(ans +(ll)lvl_map[d+1].size()*((ll)lvl_map[d].size()-1))%mod;
        }
    }
    cout<<ans%mod<<"\n";
}
 
int main() {
    #ifndef ONLINE_JUDGE
        freopen("Error.txt", "w", stderr);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int test = 1;
    cin >> test;
    while(test--){
         solve();
    }
    
    return 0;
}
