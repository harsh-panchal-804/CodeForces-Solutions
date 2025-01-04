#include<iostream>
#include<vector>
#include<iomanip>
#include<string.h>
#include<algorithm>
using namespace std;
void solve(){
    int n;
    cin>>n;
    string str;
    cin>>str;
    if(str.find("...")!=string::npos){
        cout<<"2"<<endl;
        return;
    }
    int c=count(str.begin(),str.end(),'.');
    cout<<c<<endl;
    return;
}
int main(){
    int test;
    cin>> test;
    for(int t=0;t<test;t++){
        solve();

    }
    return 0;
}