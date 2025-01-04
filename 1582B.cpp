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
    
    long long a=0;
    long long b=0;
    for(int i=0;i<n;i++){
        long long x;
        cin>>x;
        if(x==1)a++;
        if(x==0)b++;
    }
    cout<<(1ll<<b)*(long long)a<<'\n';

}
int main(){
    int test;
    cin>>test;
    while(test--){
        solve();
    }
    return 0;
}