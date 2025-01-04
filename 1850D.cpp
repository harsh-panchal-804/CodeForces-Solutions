#include<iostream>
#include<vector>
#include<iomanip>
#include<string.h>
#include<algorithm>
using namespace std;
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int>vec(n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
    sort(vec.begin(),vec.end());
    int count=1;
    int ans=1;
    for(int i=1;i<n;i++){
        if(vec[i]-vec[i-1]>k){
            count=1;
        }
        else{
            count++;
        }
        ans=max(ans,count);
    }
    cout<<n-ans<<endl;
}
int main(){
    int test;
    cin>>test;
    while(test--){
        solve();
    }
    return 0;
}