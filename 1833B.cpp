#include<iostream>
#include<vector>
#include<iomanip>
#include<string.h>
#include<algorithm>
#include<unordered_map>
using namespace std;
void solve(){
    int n,k;
    cin>>n>>k;
    string s ;
    cin>>s;
    int count=0;
    unordered_map<char,int> map;
    for(auto i : s){
        map[i]++;
    }
    for(auto i : map){
        if(i.second %2!=0){
            count++;
        }
    }
    if(count>k+1){
        cout<<"NO"<<endl;
        return;
    }
    else cout<<"YES"<<endl;

}
int main(){
    int test;
    cin>>test;
    while(test--){
        solve();
    }
    return 0;
}