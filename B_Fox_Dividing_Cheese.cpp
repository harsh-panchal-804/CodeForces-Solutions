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
int divv(int a,int base){
    int ans=0;
    while(a%base==0){
        ans++;
        a/=base;
    }
    return ans;
}
long long int_pow(int a, int b) {
    if (b == 0)
        return 1;
    long long half = int_pow(a, b / 2);
    if (b % 2 == 0)
        return half * half;
    else
        return a * half * half;
}

void solve(){
    ll a,b;
    cin>>a>>b;
    /// if a,b div by 2 eat half
    /// if a,b div by 3 eat 2/3
    /// if a,b div by 5 ear 4/5
    ll a1=divv(a,2);
    ll a2=divv(a,3);
    ll a3=divv(a,5);
    ll b1=divv(b,2);
    ll b2=divv(b,3);
    ll b3=divv(b,5);
    ll x=(a/(int_pow(2,a1)*int_pow(3,a2)*int_pow(5,a3)));
    ll y=(b/(int_pow(2,b1)*int_pow(3,b2)*int_pow(5,b3)));
    if(x!=y){
        cout<<-1<<"\n";
    }
    else{
        cout<<abs(a1-b1)+abs(a2-b2)+abs(a3-b3)<<"\n";
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
