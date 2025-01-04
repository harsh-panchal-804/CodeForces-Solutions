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
const int max_n=1e5+100;
int n,q;
int arr[max_n];
int block_size;
int freq[max_n];
struct Query{
    int l,r,idx;
    bool operator<(const Query &b) const {
    if (l / block_size != b.l / block_size)
        return l / block_size < b.l / block_size;
    return r < b.r;
}

};
int curr_ans=0;
void add(int index,int delta){
    int element=arr[index];
    if(element>=max_n || element<0)return;
    if(freq[element]==element)curr_ans--;
    freq[element]+=delta;
    if(freq[element]==element)curr_ans++;
}

void solve(){
    cin>>n>>q;
    block_size= sqrt(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<Query> queries(q);
    for(int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;
        queries[i].l=a-1;
        queries[i].r=b-1;
        queries[i].idx=i;
    }
    vector<int>ans(queries.size());
    // debug(queries)
    sort(all(queries));
    int curr_l=0;
    int  curr_r=-1;
    for(auto&q : queries){
        int l=q.l;
        int r=q.r;
        int idx=q.idx;
        while(curr_l >l) add(--curr_l,1);
        while(curr_r <r)add(++curr_r,1);
        
        while(curr_l <l) add(curr_l++,-1);
        while(curr_r  > r)add(curr_r--,-1);
        ans[idx]=curr_ans;
    }
    for(auto i : ans){
        cout<<i<<"\n";
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
