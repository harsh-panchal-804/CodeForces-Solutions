#include<iostream>
#include<vector>
#include<iomanip>
#include<string.h>
#include<algorithm>
using namespace std;
void solve(){
    int a,b,c;
    cin>>a>>b>>c;
    if(c%2!=0){
        if(a>b)cout<<"First"<<endl;
        else if(a<b)cout<<"Second"<<endl;
        else  cout<<"First"<<endl;
        return;
    }
    else{
        if(a>b)cout<<"First"<<endl;
        else if(a<b)cout<<"Second"<<endl;
        else  cout<<"Second"<<endl;
        
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