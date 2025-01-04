#include<iostream>
#include<vector>
#include<iomanip>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
void solve(){
    long long n;
    cin>>n;
    if(floor(log2l(n))==ceil(log2l(n)))cout<<"NO"<<"\n";
    else cout<<"YES"<<"\n";
}
int main(){
    int test;
    cin>>test;
    while(test--){
        solve();
    }
    return 0;
}