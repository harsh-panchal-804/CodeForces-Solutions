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
int d;

const int M = 30001;

int dp[M][250*2];
bool used[M][250*2] = {};


int dfs(vector<int>& vec,int prev,int curr){
    int jj = prev-(d-250);
    if (curr >= M) return 0;
    if (used[curr][jj]) return dp[curr][jj];
    used[curr][jj] = true;
    int ans;
    if(prev==1){
        ans=vec[curr]+max(dfs(vec,prev,curr+prev),dfs(vec,prev+1,curr+prev+1));
    }
    else{
        ans=vec[curr]+max({dfs(vec,prev,curr+prev),dfs(vec,prev+1,curr+prev+1),dfs(vec,prev-1,curr+prev-1)});
    }
    return dp[curr][jj]=ans;
}


void solve(){
    int n;
    cin>>n>>d;
    vector<int> vec(30001,0);
   
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        vec[x]++;
    }
    int ans=dfs(vec,d,d);
    cout<<ans<<"\n";
    
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
