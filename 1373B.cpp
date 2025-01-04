#include<iostream>
#include<vector>
#include<iomanip>
#include<string.h>
#include<algorithm>
using namespace std;
void solve(){
    string s ;
    cin>>s;
    int a=count(s.begin(),s.end(),'0');
    int b=count(s.begin(),s.end(),'1');
    int ans=min(a,b);
    if(ans%2==0){
        cout<<"NET"<<"\n";
    }
    else cout<<"DA"<<"\n";
}
int main(){
    int test;
    cin>>test;
    while(test--){
        solve();
    }
    return 0;
}