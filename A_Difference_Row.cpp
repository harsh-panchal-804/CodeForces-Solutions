#include<bits/stdc++.h>
#define ll long long
#define INF (1LL << 60)
#define inf 1<<30
const long long mod=1e9 +7;
using namespace std;
vector<int> sieve(int n){
    vector<bool> vec(n+1,true);
    vec[0]=vec[1]=false;
    for(int i=2;i<n+1;i++){
        if(vec[i]==true){
            for(int j=2*i;j<n+1;j+=i){
                vec[j]=false;
            }
        }
    }
    vector<int> ans;
    for(int i=0;i<n+1;i++){
        if(vec[i]){
            ans.push_back(i);
        }
    }
    return ans;
}
void solve(){
    int n;
    cin>>n;
    vector<int> vec(n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
    int c=count_if(vec.begin(),vec.end(),[&](int x){
        return x==vec[0];
    });
    if(c==n){
        for(auto i : vec){
            cout<<i<<" ";
        }
        cout<<"\n";
        return ;
    }
    auto first_ele=max_element(vec.begin(),vec.end());
    auto last_ele=min_element(vec.begin(),vec.end());
    priority_queue<int,vector<int>,greater<int>>pq;
    for(int i=0;i<n;i++){
        if(vec.begin()+i==first_ele|| i+vec.begin()==last_ele)continue;
        pq.push(vec[i]);
    }
    cout<<*first_ele<<" ";
    while(!pq.empty()){
       
        cout<<pq.top()<<' ';
        pq.pop();
    }
    cout<<*last_ele<<'\n';

    

}

int main(){
    
    solve();
    
    return 0;
}