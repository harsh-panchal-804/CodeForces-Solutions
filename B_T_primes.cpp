#include<bits/stdc++.h>
#define ll long long
#define INF (1LL << 60)
#define inf 1<<30
const long long mod=1e9 +7;
using namespace std;
vector<bool> sieve(int n){
    vector<bool> vec(n+1,true);
    vec[0]=vec[1]=false;
    for(int i=2;i<n+1;i++){
        if(vec[i]==true){
            for(int j=2*i;j<n+1;j+=i){
                vec[j]=false;
            }
        }
    }
    // vector<int> ans;
    // for(int i=0;i<n+1;i++){
    //     if(vec[i]){
    //         ans.push_back(i);
    //     }
    // }
    return vec;
}
void solve(){
    int n;
    cin>>n;
    vector<ll> vec(n);
    for(int i=0;i<n;i++)cin>>vec[i];
    vector<bool> primes=sieve(1e6+100);
    for(ll i : vec){
        ll sqr=sqrt(i);
        if(sqr*sqr!=i || primes[sqr]==false){
            cout<<"NO"<<"\n";
        }
        else cout<<"YES"<<"\n";

    }

}

int main(){
  
    solve();
    
    return 0;
}