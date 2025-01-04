#include<iostream>
#include<vector>
#include<iomanip>
#include<string.h>
#include<algorithm>
using namespace std;
void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int l=0;
    int r=s.size()-1;
    while(l<r &&((s[l]=='0' && s[r]=='1')||(s[l]=='1'&&s[r]=='0'))){
        l++;
        r--;
    }
    cout<<r-l+1<<endl;
}
int main(){
    int test;
    cin>>test;
    while(test--){
        solve();
    }
    return 0;
}