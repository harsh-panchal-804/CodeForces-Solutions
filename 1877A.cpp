#include<iostream>
#include<vector>
#include<iomanip>
#include<string.h>
#include<algorithm>
using namespace std;
void solve(){
    int n;
    cin>>n;
    int sum=0;
    for(int i=0;i<n-1;i++){
        int x;
        cin>>x;
        sum+=x;
    }
    cout<<sum*-1<<endl;
    return;
}
int main(){
    int test;
    cin>>test;
    for(int i=0;i<test;i++){
        solve();
    }
    return 0;
}