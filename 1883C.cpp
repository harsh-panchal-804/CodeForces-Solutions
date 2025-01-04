#include<iostream>
#include<vector>
#include<iomanip>
#include<string.h>
#include<algorithm>
using namespace std;
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> vec(n);
    int even=0;
    int d=k-1;
    for(int i=0;i<n;i++){
        cin>>vec[i];
        if(vec[i]%2==0)even++;
        if(vec[i]%k==0){
           d=0;
        }
        else d=min(d,k-vec[i]%k);
    }
    if(k!=4){
        cout<<d<<"\n";
    }
    else{
        if(even>=2){
            cout<<0<<"\n";
        }
        else if(even==1){
            cout<<min(d,1)<<"\n";
        }
        else{
            cout<<min(2,d)<<"\n";
        }
    }
    
    
    
    
    
}
int main(){
    int test;
    cin>> test;
    while(test--){
        solve();
    }
    return 0;
}