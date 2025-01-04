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
    int n,m;
    cin>>n>>m;
    vector<int>indegree(n+1,0);
    for(int i=0;i<n;i++){
        int u,v;
        cin>>u>>v;
        indegree[u]++;
        indegree[v]++;
    }
    int star_node;
    for(int i=1;i<n+1;i++){
        if(indegree[i]==0){
            star_node=i;
        }
    }
    cout<<n-1<<"\n";
  
    for(int j=1;j<n+1;j++){
        if(j==star_node)continue;
        cout<<star_node<<" "<<j<<'\n';
    }
    
}

int main(){

    solve();
    
    return 0;
}