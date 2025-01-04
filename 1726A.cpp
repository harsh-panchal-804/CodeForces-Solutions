#include<iostream>
#include<vector>
#include<iomanip>
#include<string.h>
#include<algorithm>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int> vec(n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
    int ans=INT32_MIN;
    for(int i=0;i<n;i++){
        ans=max(ans,(vec[(i+n-1)%n]-vec[i]));
    }
    for(int i=1;i<n;i++){
        ans=max(ans,vec[i]-vec[0]);
    }
    for(int i=0;i<n-1;i++){
        ans=max(ans,vec[n-1]-vec[i]);
    }
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