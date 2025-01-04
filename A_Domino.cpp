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
    vector<vector<int>> vec(n,vector<int>(2));
    for(int i=0;i<n;i++){
        for(int j=0;j<2;j++){
            int x;
            cin>>x;
            vec[i][j]=x%2;
        }
    }
    
    int col1=0;
    int col2=0;
    int check=0;
    for(int i=0;i<n;i++){
        if(vec[i][0]!=vec[i][1])check++;
    }
    for(int i=0;i<n;i++){
        col1+=vec[i][0];
    }
    for(int i=0;i<n;i++){
        col2+=vec[i][1];
    }
    if(col1%2==0 && col2%2==0 ){
        cout<<0<<'\n';
    }
    else if(col1%2 && col2%2&& check>0){
        cout<<1<<"\n";
    }
    else{
        cout<<-1<<"\n";
    }

}

int main(){
    
         solve();
    
    return 0;
}