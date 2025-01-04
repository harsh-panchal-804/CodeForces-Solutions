#include<iostream>
#include<vector>
#include<iomanip>
#include<string.h>
#include<algorithm>
using namespace std;
void solve(){
    int n ,a ,b;
    cin>>n>>a>>b;
    if(n==a&& a==b){
        cout<<"YES"<<endl;
        return;
    }
    else if(n-a-b>=2){
        cout<<"YES"<<endl;
    }
    else cout<<"NO"<<endl;
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