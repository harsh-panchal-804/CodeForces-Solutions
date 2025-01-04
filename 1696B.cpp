#include<iostream>
#include<vector>
#include<iomanip>
#include<string.h>
#include<algorithm>
using namespace std;
void  solve(){
    int n;
    cin>>n;
    vector<int>vec(n);
    bool flag=true;
    for(int i=0;i<n;i++){
        cin>>vec[i];
        flag =flag &&(vec[i]==0);
    }
    if(flag){
        cout<<0<<endl;
        return;
    }
    int l=0;
    int r=n-1;
    while(vec[l]<=0){
        l++;
    }
    while(vec[r]<=0) r--;
    bool flag2=false;
    for(int i=l;i<=r;i++){
        flag2=flag2 ||(vec[i]==0);
    }
    if(flag2){
        cout<<2<<endl;
        return;
    }
    else{
        cout<<1<<endl;
        return;
    }
}
int main(){
    int test;
    cin>>test;
    while(test--){
        solve();
    }
    return 0;
}