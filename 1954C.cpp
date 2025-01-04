#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;
int main(){
    int test;
    cin>>test;
    for(int i=0;i<test;i++){
    string x,y;
    cin>>x;
    cin>>y;
    bool flag=false;
    for(int i=0;i<x.size();++i){
        if((x[i]>y[i])== flag)swap(x[i],y[i]);
        flag =flag || (x[i]!=y[i]);
    }
    cout<<x<<endl;
    cout<<y<<endl;
    }
    
    return 0;
}