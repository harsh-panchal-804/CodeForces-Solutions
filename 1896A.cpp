#include<iostream>
#include<vector>
#include<iomanip>
#include<string.h>
#include<algorithm>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        nums[i]=x;
    }
    if(nums[0]==1){
        cout<<"YES"<<endl;
        return;
    }
    else{
        cout<<"NO"<<endl;
        return;
    }
}
int main(){
    int test;
    cin>>test;
    for(int t=0;t<test;t++){
        solve();
    }
    return 0;
}