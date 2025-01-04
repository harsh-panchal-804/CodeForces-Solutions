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
    ll sum=0;
    for(int i=0;i<n;i++){
        cin>>vec[i];
        sum+=vec[i];
    }
    int mid=sum/n;
    int ok=0;
    for(int i=0;i<n-1;i++){
        if(vec[i]==mid)ok++;
        else if(vec[i]>mid){
            vec[i+1]+=(vec[i]-mid);
            vec[i]=mid;
            ok++;
        }
        else{
            vec[i+1]-=(mid-vec[i]);
            vec[i]=mid;
            ok++;
        }
    }
    if(vec[n-1]==mid)ok++;
    cout<<ok<<"\n";

}

int main(){
    
   
        solve();
    
    return 0;
}