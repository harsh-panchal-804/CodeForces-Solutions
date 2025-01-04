#include<iostream>
#include<vector>
#include<iomanip>
#include<string.h>
#include<algorithm>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int> vec(n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
    // int i;
    // int k;
    // int j;
   
    for(int j=1;j<n-1;j++){
        bool flag=false;
        bool flag2=false;
         int a;
         int b;
         int c;
        for(int i=0;i<j;i++){
            if(vec[i]<vec[j]){
                a=i;
                flag=true;
                break;
            }
        }
        for(int k=j+1;k<n;k++){
            if(vec[j]>vec[k]){
                c=k;
                flag2=true;
                break;
            }
        }
        if(flag&& flag2){
            cout<<"YES"<<"\n";
            cout<<a+1<<" "<<j+1<<" "<<c+1<<"\n";
            return;
        }
    }
    
    cout<<"NO"<<"\n";
}
int main(){
    int test;
    cin>>test;
    while(test--){
        solve();
    }
    return 0;
}