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
vector<pair<int,int>> whites;
vector<pair<int,int>> blacks;
bool reachable(pair<int,int> a,pair<int,int>b ){
    int x1=a.first;
    int y1=a.second;
    int x2=b.first;
    int y2=b.second;
    bool first=true;
    int x_inc=x2>x1?1:-1;
    int y_inc=y2>y1?1:-1;
    //// x2 - x1
    ///// y1 -y2
    while(x1!=x2){
        
    }

}



void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>> vec(n,vector<char>(m));
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char c;
            cin>>c;
            vec[i][j]=c;
            if(c=='W'){
                whites.push_back({i,j});
            }
            else{
                blacks.push_back({i,j});
            }
        }
    }
    for(int i=0;i<blacks.size();i++){
        for(int j=i+1;j<blacks.size();j++){
            if(!reachable(blacks[i],blacks[j],vec)){
                cout<<"NO"<<"\n";
            }
        }
    }
    cout<<"YES"<<"\n";
    
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
