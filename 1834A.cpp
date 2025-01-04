#include<iostream>
#include<vector>
#include<iomanip>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    int sum=0;
    int prod=1;
    int turn=0;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        sum+=x;
        prod*=x;
    }
    if(sum>=0 && prod==1){
        cout<<turn<<endl;
        return;
    }
    else if(sum<0){
        turn =turn +ceil(abs(sum)/2);
        if(prod==-1){
            cout<<turn+1<<endl;
        }
        else{
            cout<<turn<<endl;
        }
        return;

    }

}
int main(){
    int test;
    cin>>test;
    while(test--){
        solve();
    }
    return 0;
}