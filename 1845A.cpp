#include<iostream>
#include<vector>
#include<iomanip>
#include<string.h>
#include<algorithm>
using namespace std;
void solve(){
    int n,k,x;
    cin>>n>>k>>x;
    if(x!=1){
        cout<<"YES"<<endl;
        cout<<n<<endl;
        for(int i=0;i<n;i++){
            cout<<1<<" ";
        }
        cout<<endl;
        return;
    }
    else if(k==1 || (k==2 && n%2==1)){
        cout<<"NO"<<endl;
        return;
    }
    else{
        cout<<"YES"<<endl;
        cout<<n/2<<endl;
        if(n%2==0){
            for(int i=0;i<n/2;i++){
                cout<<2<<" ";
            }
            cout<<endl;
            return;
        }
        else{
            cout<<3<<" ";
            for(int i=0;i<(n/2)-1;i++){
                cout<<2<<" ";
            }
            cout<<endl;
            return;
        }
    }
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