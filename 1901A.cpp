#include<iostream>
#include<vector>
#include<iomanip>
#include<string.h>
#include<algorithm>
using namespace std;
void solve(){
        int n,x;
        cin>>n>>x;
        vector<int> gas(n);
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            gas[i]=x;
        }
        // if(n==1){
        //     cout<<gas[0]<<endl;
        //     return;
        // }
        int a=-1;
        int prev=0;
        for(int i=0;i<gas.size();i++){
            a=max(a,gas[i]-prev);
            prev=gas[i];
        }
        
        a=max(a,2*(x-gas[n-1]));
        cout<<a<<endl;
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