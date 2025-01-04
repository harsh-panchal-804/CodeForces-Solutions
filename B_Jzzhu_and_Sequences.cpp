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
    int x,y;
    cin>>x>>y;
    int n;
    cin>>n;
    int mod=1e9+7;
    if(n==2){
        cout<<(y+mod)%mod<<"\n";
        return;
    }
    if(n==1){
        cout<<(x+mod)%mod<<"\n";
        return;
    }
    vector<int> ans(6);
    ans[0]=(x+mod)%mod;
    ans[1]=(y+mod)%mod;
    for(int i=2;i<6;i++){
        ans[i]=(((mod+ans[i-1])%mod-(mod+ans[i-2])%mod)+mod)%mod;
    }

    n--;
    n%=6;
    cout<<ans[n]<<"\n";
    

}

int main(){
    
    solve();
    
    return 0;
}