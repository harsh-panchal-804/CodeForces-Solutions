#include<iostream>
#include<vector>
#include<iomanip>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    int diff=1e9;
    vector<int> nums(n);

    for(int i=0;i<n;i++){
        cin>>nums[i];
        if(i>0){
            diff=min(diff,nums[i]-nums[i-1]);
        }
    }
    if(!is_sorted(nums.begin(),nums.end())){
        cout<<0<<endl;
        return;
    }
    cout<<diff/2+1<<endl;
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