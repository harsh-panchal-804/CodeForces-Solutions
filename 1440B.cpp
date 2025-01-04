#include<iostream>
#include<vector>
#include<iomanip>
#include<string.h>
#include<algorithm>
using namespace std;
void solve(){
    long long  n,k;
    cin>>n>>k;

    vector<long long >vec(n*k);
    for(long long i=0;i<n*k;i++){
        cin>>vec[i];
    }
    if(n==1){
        long long sum=0;
        for(auto i : vec)sum+=i;
        cout<<sum<<"\n";
        return;
    }
    long long  mid=(n-1)/2;
    long long  left=n-mid;
    long long  ans=0;
    long long  count=0;
    for(int i=n*k-left;i>=0;i-=left){
        ans+=vec[i];
        count++;
        if(count==k)break;
    }
    cout<<ans<<"\n";
    return;
}

int main(){
    int test;
    cin>>test;
    while(test--){
        solve();
    }
    return 0;
}