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
    ll n,k;
    cin>>n>>k;
    ll a[n+1],pre[n+1];
    pre[0]=0;
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i];
        pre[i]=pre[i-1]+a[i];
    }
    ll dp[n+1],ind[n+1];
    dp[k]=pre[k];
    ind[k]=1;
    for(ll i=k+1;i<=n;i++)
    {
        if(pre[i]-pre[i-k]>dp[i-1])
        {
            dp[i]=pre[i]-pre[i-k];
            ind[i]=i-k+1;
        }
        else
        {
            dp[i]=dp[i-1];
            ind[i]=ind[i-1];
        }
    }
    ll sum=LLONG_MIN;
    ll ind1,ind2;
    for(ll i=2*k;i<=n;i++)
    {
        if(dp[i-k]+pre[i]-pre[i-k]>sum)
        {
            sum=dp[i-k]+pre[i]-pre[i-k];
            ind1=ind[i-k];
            ind2=i-k+1;
        }
    }
    cout<<ind1<<" "<<ind2;
    return ;
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
