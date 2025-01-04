#include<iostream>
#include<vector>
#include<iomanip>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
void solve(){
    long long n,x;
    cin>>n>>x;
    long long sum=0;
    vector<int>vec(n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
        sum+=vec[i];
    }
    long long  mi=sum/x + (sum%x !=0);
    long long  mx=0;
    for(auto i : vec){
        mx+=i/x + (i%x!=0);
    }
    cout<<mi<<" "<<mx<<"\n";
}
int main(){
    int test;
    cin>>test;
    while(test--){
        solve();
    }
    return 0;
}