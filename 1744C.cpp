#include<iostream>
#include<vector>
#include<iomanip>
#include<string.h>
#include<algorithm>
using namespace std;
void solve(){
    int n;
    char c;
    cin>>n>>c;
    string s;
    cin>>s;
    s=s+s;
    int last=-1;
    int ans=INT32_MIN;
    for(int i=s.size()-1;i>=0;i--){
        if(s[i]=='g'){
            last=i;
        }
        if(s[i]==c){
            ans=max(ans,last-i);
        }
    }
    cout<<ans<<"\n";
    
}
int main(){
    int test;
    cin>>test;
    while(test--){
        solve();
    }
    return 0;
}