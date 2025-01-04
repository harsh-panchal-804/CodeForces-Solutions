#include<iostream>
#include<vector>
#include<iomanip>
#include<string.h>
#include<algorithm>
using namespace std;
void solve(){
    int n;
    cin>>n;
    int count=0;
    if(n==1){
        cout<<0<<"\n";
        return;
    }
    while(n>1){
    if(n%6==0){
        n=n/6;
        
    }
    else if (n%2!=0){
        n=n*2;
    }
    else{
        cout<<-1<<"\n";
        return;
    }
    count++;
    }
    
    
    if(n!=1){
        cout<<-1<<"\n";
        return;
    }
    else{
        cout<<count<<"\n";
        return;
    }


}
int main(){
    int test;
    cin>>test;
    while(test--){
        solve();
    }
    return 0;
}