#include<iostream>
#include<vector>
#include<iomanip>
#include<string.h>
#include<algorithm>
using namespace std;
void solve(){
    int n,k;
    cin>>n>>k;
    bool flag=false;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(x==k){
            flag=flag || true;
        }
    }
    if(flag==true){
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
    for(int i=0;i<test;i++){
        solve();
    }
    return 0;
}