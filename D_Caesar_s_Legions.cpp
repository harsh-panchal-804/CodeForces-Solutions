#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
const long long mod = 1e8;
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
int dp[101][101][11][11];
int dfs(int n1,int n2,int k1,int k2,int prev_k,int prev_h){
    if(n1==0 && n2==0)return 1;
    if(dp[n1][n2][prev_k][prev_h]!=-1)return dp[n1][n2][prev_k][prev_h];
    ///place footmen
    int ans=0;
    int op1= prev_k+1 <= k1 && n1>0 ? dfs(n1-1,n2,k1,k2,prev_k+1,0):0;
    int op2= prev_h+1 <= k2 && n2>0 ? dfs(n1,n2-1,k1,k2,0,prev_h+1):0;
    ans=(ans+op1+op2)%mod;
    // if(prev_k+1 <=k1 && n1>0){
    //     ans=(ans+dfs(n1-1,n2,k1,k2,prev_k+1,0))%mod;
    // }
    // if(prev_h+1 <=k2 && n2>0){
    //     ans=(ans+dfs(n1,n2-1,k1,k2,0,prev_h+1))%mod;
    // }
    return dp[n1][n2][prev_k][prev_h]=ans;
}


void solve(){
    int n1,n2,k1,k2;
    cin>>n1>>n2>>k1>>k2;
    memset(dp,-1,sizeof(dp));
    int ans=dfs(n1,n2,k1,k2,0,0);
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
