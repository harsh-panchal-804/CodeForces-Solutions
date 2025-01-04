#include<iostream>
#include<vector>
#include<iomanip>
#include<string.h>
#include<algorithm>
using namespace std;
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> vec(n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
    int value=0;
    for(int i=0;i<k;i++){
        value+=vec[i];
    }
    int index=0;
    int ans=value;
    for(int i=1;i<n-k+1;i++){
        ans+=vec[i+k-1];
        ans-=vec[i-1];
        if(ans<value){
            value=ans;
            index=i;
        }
    }
    cout<<index+1<<'\n';
    

}
int main(){
    solve();
    
    return 0;
}