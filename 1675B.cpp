#include<iostream>
#include<vector>
#include<iomanip>
#include<string.h>
#include<algorithm>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int>vec(n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
    int turn=0;
    for(int i=n-2;i>=0;i--){
        while(vec[i]>=vec[i+1] && vec[i]!=0){
            vec[i]=vec[i]/2;
            turn++;
        }
        if(vec[i+1]==0){
            cout<<-1<<endl;
            return;
        }
    }
    cout<<turn<<endl;
}
int main(){
    int test;
    cin>>test;
    while(test--){
        solve();
    }
    return 0;
}