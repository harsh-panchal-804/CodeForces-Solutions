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
const long long NEG_INF = -1e18;
int n, m, k;
vector<long long> prefix;
vector<vector<long long>> dp;

long long dfs(int i, int j) {
    if (j == 0) return 0;                 
    if (i < j * m) return NEG_INF;           
    if (dp[i][j] != -1) return dp[i][j];     
    long long exclude = dfs(i - 1, j);  
    long long include = dfs(i - m, j - 1) + (prefix[i] - prefix[i - m]); 

    dp[i][j] = max(exclude, include);     
    return dp[i][j];
}
void solve(){
    cin >> n >> m >> k;
    vector<long long> a(n + 1, 0);
    prefix.resize(n + 1, 0);
    dp.assign(n + 1, vector<long long>(k + 1, -1));

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        prefix[i] = prefix[i - 1] + a[i];  
    }

    cout << dfs(n, k) << endl;

}

int main(){
   
    solve();
    
    return 0;
}