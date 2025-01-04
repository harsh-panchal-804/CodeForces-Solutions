#include<iostream>
#include<vector>
#include<iomanip>
#include<string.h>
#include<algorithm>
using namespace std;
bool func(int x){
    if(x<=10){
        return true;
    }
    int nonzero=0;
    while(x){
        if(x%10!=0) nonzero++;
        if(nonzero>1)return false;
        x=x/10;
    }
    return true;
}

int main(){
    vector<int>vec;
    for(int i=1;i<999999;i++){
        if(func(i)){
            vec.push_back(i);
        }
    }
    int test;
    cin>>test;
    while(test--){
        int n;
        cin>>n;
        int count=0;
        for(auto i : vec){
            if(i<=n){
                count++;
            }
        }
        cout<<count<<endl;
    }
    return 0;
}