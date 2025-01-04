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
    ll n ,k;
    cin>>n>>k;
    deque<ll> dq(n);
    for(int i=0;i<n;i++){
        cin>>dq[i];
    }
   
    while(dq.size()>1 && k){
        ll mn=min(dq.front(),dq.back());
        if(k>=2*mn){
            dq.front()-=mn;
            dq.back()-=mn;
            k-=2*mn;
        }
        else{
            dq.front()-=(k/2 + k%2);
            dq.back()-=(k/2);
            k=0;
        }
        if(dq.front()==0)dq.pop_front();
        if(dq.back()==0)dq.pop_back();
    }
    int ans=n-dq.size();
    cout<<ans+(dq.size()&&dq.front()<=k)<<"\n";
  
}

int main(){
    int test;
    cin>>test;
    while(test--){
         solve();
    }
    return 0;
}