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
    ifstream inFile("input.txt");
    ofstream outFile("output.txt");
    int n;
    inFile>>n;
    vector<int> count(5001,0);
    vector<int> vec(n);
    for(int i=0;i<n;i++){
        inFile>>vec[i];
        count[vec[i]]++;
    }
    // int n;
    // cin>>n;
    // vector<int> vec(n);
    // for(int i=0;i<n;i++){
    //     cin>>vec[i];
    //     count[vec[i]]++;
    // }
    int ans=INT_MAX;
    for(int m=1;m<=5000;m++){
        int a=0;int b=0;
        for(int l=1;l<m;l++){
            a+=count[l];
        }
        for(int r=2*m+1;r<=5000;r++){
            b+=count[r];
        }
        ans=min(ans,a+b);
    }
    // cout<<ans<<"\n";
    outFile << ans<< endl;

    // Close file streams
    inFile.close();
    outFile.close();
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
