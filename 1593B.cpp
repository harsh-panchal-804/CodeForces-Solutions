#include<iostream>
#include<vector>
#include<iomanip>
#include<string.h>
#include<algorithm>
using namespace std;
vector<string> vec={"25","00","75","50"};
int solve(string &e,string &s){
    /// 71345
    int i=s.size()-1;
    int count=0;
    while(i>=0&&e[1]!=s[i]){
        i--;
        count++;
    }
    if(i<0)return 1000;
    i--;
    while(i>=0&&e[0]!=s[i]){
        i--;
        count++;
    }
    if(i<0)return 1000;
    return count;

}
int main(){
    int test;
    cin>>test;
    while(test--){
        int ans=INT32_MAX;
        string s;
        cin>>s;
        for(auto &e : vec){
            ans=min(ans,solve(e,s));
        }
        cout<<ans<<endl;
    }
    return 0;
}