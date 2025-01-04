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
        int l=(k-1)/(n-1);
        
        cout<<k+l<<endl;

    }
    return 0;
}