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
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
    if(vec[0]==vec[n-1]){
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    cout<<vec[n-1]<<" ";
    for(int i=0;i<n-1;i++){
        cout<<vec[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int test;
    cin>>test;
    while(test--){
        solve();
    }
    return 0;
}