#include<iostream>
#include<vector>
#include<iomanip>
#include<string.h>
#include<algorithm>
using namespace std;
void solve(){
    int a, b,n;
    cin>>a>>b>>n;
    vector<int> vec(n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
    long long  count=b;
    for(int i=0;i<n;i++){
        count+=min(vec[i],a-1);
    }
    cout<<count<<"\n";
    
}
int main(){
    int test;
    cin>>test;
    while(test--){
        solve();
    }
    return 0;
}