#include<iostream>
#include<vector>
#include<iomanip>
#include<string.h>
#include<algorithm>
using namespace std;
void solve(){
    int n,k;
    cin>>n>>k;
    vector<pair<int,int>> vec(n);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        x=x%k;
        if(x==0)x=k;
        vec[i].first=x;
        vec[i].second=i;
    }
    sort(vec.begin(),vec.end(),[](pair<int,int>&a,pair<int,int>&b){
        if(a.first!=b.first)return a.first<b.first;
        else return a.second<b.second;
    });
    for(int i=0;i<n;i++){
        cout<<vec[i].second+1<<" ";
    }
    cout<<"\n";
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