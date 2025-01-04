#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;
bool cmp(pair<pair<int,int>,char>&a,pair<pair<int,int>,char>&b){
    if(a.first.first!=b.first.first) return a.first.first<b.first.first;
    else return a.first.second>b.first.second;
}
int main(){
    string seq;
    cin>>seq;
    vector<pair<pair<int,int>,char>>vec(seq.size());//balance pos char
    int count=0;
    for(int i=0;i<seq.size();i++){
        vec.push_back({{count,i},seq[i]});
        if(seq[i]=='(')count++;
        else count--;
    }
    sort(vec.begin(),vec.end(),cmp);
    string ans="";
    for(auto i : vec){
        if(i.second=='(' || i.second==')') ans+=i.second;
    }
    cout<<ans;
    return 0;
}