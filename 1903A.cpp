#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iomanip>
using namespace std;



int main(){

    int test;
    cin>>test;
    for(int t=0;t<test;t++){
        int n,k;
        cin>>n>>k;
        vector<int> vec(n);
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            vec[i]=x;
        }
        if(is_sorted(vec.begin(),vec.end())||k>=2){
            cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;
    }
    
    return 0;
}