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
int dp[(int)1e5];
int dfs(int n,int a,int b,int c,int curr){
    if(curr>n)return -1e8;
    if(curr==n)return 0;
    if(dp[curr]!=-1)return dp[curr];
    int op1=curr+a<=n? 1+dfs(n,a,b,c,curr+a):-1e8;
    int op2=curr+b<=n? 1+dfs(n,a,b,c,curr+b):-1e8;
    int op3=curr+c<=n? 1+dfs(n,a,b,c,curr+c):-1e8;
    return dp[curr]=max({op1,op2,op3});

}
void solve(){
    int n,a,b,c;
    cin>>n>>a>>b>>c;
    memset(dp,-1,sizeof(dp));
    int ans=dfs(n,a,b,c,0);
    cout<<ans<<"\n";

}

int main(){
    solve();
    return 0;
}