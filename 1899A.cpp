#include<iostream>
#include<vector>
#include<iomanip>
#include<string.h>
#include<algorithm>
using namespace std;
void solve(){
    int n;
    cin>>n;
    if(n%3==0){
        cout<<"Second"<<endl;
        return;
    }
    else{
        cout<<"First"<<endl;
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