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
        int x;
        cin>>x;
        vec[i]=x+1;
    }
    for(int i=1;i<n;i++){
        if(vec[i]%vec[i-1]==0){
            vec[i]++;
        }
    }
    for(auto i : vec){
        cout<<i<<" ";
    }
    cout<<"\n";

}
int main(){
    int test;
    cin>>test;
    while(test--){
        solve();
    }
    return 0;
}