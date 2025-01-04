#include<iostream>
#include<vector>
#include<iomanip>
#include<string.h>
#include<algorithm>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int>vec(n);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        vec[i]=x;
    }
    int ans=0;
    int count=0;
    for(auto i : vec){
        if(i==0)count++;
        if(i==1){
            ans=max(ans,count);
            count=0;
        }
    }
    ans=max(ans,count);
    cout<<ans<<endl;
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