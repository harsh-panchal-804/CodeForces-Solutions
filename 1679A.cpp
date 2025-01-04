#include<iostream>
#include<vector>
#include<iomanip>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
void solve(){
    long long  n;

    cin>>n;
    if(n%2!=0||n<4){
        cout<<-1<<endl;
        return;
    }
    long long min=n/6;
    if(n%6!=0)min++;
    long long max=n/4;
    cout<<min<<" "<<max<<endl;
    return;
}
int main(){
    int test;
    cin>>test;
    while(test--){
        solve();
    }
    return 0;
}