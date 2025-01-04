#include<iostream>
#include<vector>
#include<iomanip>
#include<string.h>
#include<algorithm>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int>vec(n);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        cout<<n+1-x<<" ";
    }
    cout<<endl;
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