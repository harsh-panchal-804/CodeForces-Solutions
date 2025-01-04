#include<iostream>
#include<vector>
#include<iomanip>
#include<string.h>
#include<algorithm>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int> vec(n);
    for(int i=0;i<n;i++)cin>>vec[i];
    int a=vec[0];
    for(int i=1;i<n;i++){
        a=a&vec[i];
    }
    cout<<a<<'\n';
}
int main(){
    int test;
    cin>>test;
    while(test--){
        solve();
    }
    return 0;
}