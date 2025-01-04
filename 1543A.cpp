#include<iostream>
#include<vector>
#include<iomanip>
#include<string.h>
#include<algorithm>
using namespace std;
int main(){
    int test;
    cin>>test;
    while(test--){
        long long a,b;
        cin>>a>>b;
        if(a==b){
            cout<<"0"<<" "<<"0"<<"\n";
        }
        else{
            long long g=abs(a-b);
            long long  m=min(a %g,g-a%g);
            cout<<g<<" "<<m<<"\n";


        }
    }
    return 0;
}