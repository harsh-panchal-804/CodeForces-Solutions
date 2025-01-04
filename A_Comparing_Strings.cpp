#include<bits/stdc++.h>
#define ll long long
#define INF (1LL << 60)
#define inf 1<<30
const long long mod=1e9 +7;
using namespace std;
vector<int> sieve(int n){
    vector<bool> vec(n+1,true);
    vec[0]=vec[1]=false;
    for(int i=2;i<n+1;i++){
        if(vec[i]==true){
            for(int j=2*i;j<n+1;j+=i){
                vec[j]=false;
            }
        }
    }
    vector<int> ans;
    for(int i=0;i<n+1;i++){
        if(vec[i]){
            ans.push_back(i);
        }
    }
    return ans;
}
void solve(){
    string a,b;
    cin>>a>>b;
    int count=0;
    if(a.size()!=b.size()){
        cout<<"NO"<<"\n";
        return;
    }
    int first_index=-69;
    int second_index=-68;
    for(int i=0;i<a.size();i++){
        if(a[i]!=b[i]){
            if(first_index==-69){
                first_index=i;
            }
            else{
                second_index=i;
            }
            count++;
        }
    }
    if(count==1|| count>2){
        cout<<"NO"<<"\n";
        return;
    }
    swap(a[first_index],a[second_index]);
    if(a==b){
        cout<<"YES"<<"\n";
    }
    else{
        cout<<"NO"<<"\n";
    }
}

int main(){
   
    solve();
    
    return 0;
}