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
        string s ;
        cin>>s;
        vector<int> vec(2,0);
        for(auto i : s){
            vec[i-'0']++;
        }
        for(int i=0;i<s.size()+1;i++){
            if(i==s.size()||(vec[1-(s[i]-'0')]==0)){
                cout<<s.size()-i<<"\n";
                break;
            }
            vec[1-(s[i]-'0')]--;
        }


    }
    return 0;
}