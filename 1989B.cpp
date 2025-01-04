#include<iostream>
#include<vector>
#include<iomanip>
#include<string.h>
#include<algorithm>
using namespace std;
void solve(){
    string a ,b;
    cin>>a>>b;
    int ans=a.size();
    int m=a.size();
    int n=b.size();
    vector<vector<int>>dp(m+1,vector<int>(n+1,0));
    for(int i=1;i<m+1;i++){
        for(int j=1;j<n+1;j++){
            if(a[i-1]==b[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
  
    cout<<ans+(n-dp[m][n])<<"\n";

}
int main(){
    int test;
    cin>>test;
    while(test--){
        solve();
    }
    return 0;
}