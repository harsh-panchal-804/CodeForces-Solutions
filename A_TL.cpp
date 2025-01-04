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
bool check(int mid,vector<int>& cor){
    bool flag=false;
    for(auto i : cor){
        if(2*i<=mid)flag=true;
    }
    return flag;
}
void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> cor(n);
    vector<int>incor(m);
    for(int i=0;i<n;i++)cin>>cor[i];
    for(int i=0;i<m;i++)cin>>incor[i];
    sort(cor.begin(),cor.end());
    sort(incor.begin(),incor.end());

    int ans=2*cor[0];
    ans=max(ans,cor[n-1]);
    if(incor[0]<=ans){
        cout<<-1<<"\n";
    }
    else {
        cout<<ans<<"\n";
    }
}

int main(){
    
    solve();
    
    return 0;
}