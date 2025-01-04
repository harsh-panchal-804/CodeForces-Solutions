#include<iostream>
#include<vector>
#include<iomanip>
#include<string.h>
#include<algorithm>
#include<map>
using namespace std;
void solve(){
    int n;
    cin>>n;
    map<int,int> map;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        map[x]++;
    }
    if(map.size()>2){
        cout<<"NO"<<endl;
        return;
    }
    else{
        if(abs(map.begin()->second  - map.rbegin()->second)<=1){
            cout<<"YES"<<endl;
            return;
        }
        else{
            cout<<"NO"<<endl;
            return;
        }
    }
}
int main(){
    int test;
    cin>>test;
    for(int t=0;t<test;t++){
        solve();

    }
    return 0;
}