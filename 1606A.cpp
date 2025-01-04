#include<iostream>
#include<vector>
#include<iomanip>
#include<string.h>
#include<algorithm>
using namespace std;
void solve(){
    string s;
    cin>>s;
    if(s[0]==s[s.size()-1]){
        cout<<s<<endl;
        return;
    }
    else{
        s[0]=s[s.size()-1];
        cout<<s<<endl;
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