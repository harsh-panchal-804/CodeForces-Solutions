#include<iostream>
#include<vector>
#include<iomanip>
#include<string.h>
#include<algorithm>
using namespace std;

void solve(){
    int ans=1000000;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        ans=min(ans,abs(x));
    }
    cout<<ans<<endl;
}
int main(){
    solve();
    return 0;
}