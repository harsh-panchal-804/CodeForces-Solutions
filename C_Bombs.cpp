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
    int n;
    cin>>n;
    vector<pair<int,int>> vec;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        vec.push_back({x,y});
    }
    sort(all(vec),[&](pair<int,int>&a ,pair<int,int>&b){
        return abs(a.first)+abs(a.second)<abs(b.first)+abs(b.second);
    });
  
    int k=0;
    for(auto & bomb:vec){
        if(bomb.first!=0){
            k+=2;
        }
        if(bomb.second!=0){
            k+=2;
        }
        k+=2;
    }
    cout<<k<<"\n";
    for(auto &bomb:vec){
        int x=bomb.first;
        int y=bomb.second;
        if(x){
            cout<<"1 ";
            cout<<abs(x)<<" ";
            if(x>0){
                cout<<"R"<<"\n";
            }
            else cout<<"L"<<"\n";
        }
        if(y){
            cout<<"1 ";
            cout<<abs(y)<<" ";
            if(y>0){
                cout<<"U\n";
            }
            else cout<<"D\n";
        }
        cout<<"2\n";
        if(x){
            cout<<"1 ";
            cout<<abs(x)<<" ";
            if(x>0){
                cout<<"L"<<"\n";
            }
            else cout<<"R"<<"\n";
        }
        if(y){
            cout<<"1 ";
            cout<<abs(y)<<" ";
            if(y>0){
                cout<<"D\n";
            }
            else cout<<"U\n";
        }
        cout<<"3\n";
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
