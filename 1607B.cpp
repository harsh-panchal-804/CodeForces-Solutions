#include<iostream>
#include<vector>
#include<iomanip>
#include<string.h>
#include<algorithm>
using namespace std;
void solve(){
    long long  x,n;
    cin>>x>>n;
    long long d=0;
    if(n%4==1)d=n;
    else if(n%4==2)d=-1;
    else if(n%4==3)d=-n-1;
    else if(n%4==0) d=0;
    if(x%2==0)cout<<x-d<<endl;
    else cout<<x+d<<endl;
    
}
int main(){
    int test;
    cin>>test;
    while(test--){
        solve();
    }
    return 0;
}