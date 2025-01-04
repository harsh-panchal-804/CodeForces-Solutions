#include<iostream>
#include<vector>
#include<iomanip>
#include<string.h>
#include<algorithm>
using namespace std;
void solve(){
    int a,b,c;
    cin>>a>>b>>c;
    int r1=2*b-c;
    int m=r1/a;
    if(r1>0 && m>0 && a*m==r1){
        cout<<"YES"<<"\n";
        return;
    }
    int r2=(a+c)/2;
    int m2=r2/b;
    if(r2>0 && m2>0 &&(a+c)%2==0 &&b*m2==r2){
        cout<<"YES"<<"\n";
        return;
    }
    int r3=2*b-a;
    int m3=r3/c;
    if(m3>0 && r3>0 && m3*c==r3){
        cout<<"YES"<<"\n";
        return;
    }
    cout<<"NO"<<"\n";
}
int main(){
    int test;
    cin>>test;
    while(test--){
        solve();
    }
    return 0;
}