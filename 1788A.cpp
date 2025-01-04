#include<iostream>
#include<vector>
#include<iomanip>
#include<string.h>
#include<algorithm>
using namespace std;
void solve(){
    int n;
    cin>>n;
    int twocount=0;
    vector<int> vec(n);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        vec[i]=x;
        if(x==2)twocount++;
    }
    if(twocount%2!=0){
        cout<<-1<<endl;
        return;
    }
    // if(twocount==0){
    //     cout<<1<<endl;
    //     return;
    // }
    twocount=twocount/2;
    int count=0;
    
    for(int i=0;i<n;i++){
        if(vec[i]==2)count++;
        if(count==twocount){
            cout<<i+1<<endl;
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