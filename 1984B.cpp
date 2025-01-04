#include<iostream>
#include<vector>
#include<iomanip>
#include<string.h>
#include<algorithm>
using namespace std;
void solve(){
    long long n;
    cin>>n;
    if(n%10==9){
        cout<<"NO"<<"\n";
        return;
    }
    n=n/10;
    int last;
    while(n){
        if(n%10==0){
            cout<<"NO"<<"\n";
            return;
        }
        last=n;
        n/=10;
    }
    if(last==1){
        cout<<"YES"<<"\n";
    }
    else cout<<"NO"<<"\n";
}
int main(){
    int test;
    cin>>test;
    while(test--){
        solve();
    }
    return 0;
}