#include<iostream>
#include<vector>
#include<iomanip>
#include<string.h>
#include<algorithm>
using namespace std;
void solve(){
    int n,m;
    cin>>n>>m;
    string x,s;
    cin>>x>>s;
    for(int i=0;i<6;i++){
        if(x.find(s)!=string::npos){
            cout<<i<<endl;
            return;
        }
        x=x+x;
    }
    cout<<-1<<endl;
}
int main(){
    int test;
    cin>>test;
    for(int t=0;t<test;t++){
        solve();
    }
    return 0;
}