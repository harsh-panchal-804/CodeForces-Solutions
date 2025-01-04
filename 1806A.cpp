#include<iostream>
#include<vector>
#include<iomanip>
#include<string.h>
#include<algorithm>
using namespace std;
void solve(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if(d>=b && a-b>=c-d){
        cout<<(d-b + (a+ d-b)-c)<<endl; 
    }
    else{
        cout<<-1<<endl;
    }
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