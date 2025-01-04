#include<iostream>
#include<vector>
#include<iomanip>
#include<string.h>
#include<algorithm>
using namespace std;
void solve(){
    long long n,k,q;
    cin>>n>>k>>q;
    long long len=0;
    long long ans=0;
    for(long long i=0;i<n;i++){
        long long  x;
        cin>>x;
        if(x<=q){
            len+=1;
        }
        else{
            if(len>=k){
                ans+= ((len-k+1)*(len-k+2))/2;
            }
            len=0;
        }
    }
   
    if(len>=k) ans+=((len-k+1)*(len-k+2))/2;
    cout<<ans<<'\n';
}
int main(){
    int test;
    cin>>test;
    while(test--){
        solve();
    }
    return 0;
}