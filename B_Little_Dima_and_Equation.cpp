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
long long int_pow(int a, int b) {
    if (b == 0)
        return 1;
    long long half = int_pow(a, b / 2);
    if (b % 2 == 0)
        return half * half;
    else
        return a * half * half;
}

int dig_sum(int x){
    int ans=0;
    while(x){
        ans+=x%10;
        x/=10;
    }
    return ans;
}
void solve(){
    int a,b,c;
    cin>>a>>b>>c;
    vector<int> fans;
    for(int i=1;i<=81;i++){
        ll num=b*(int_pow(i,a))+c;
        if(i==dig_sum(num) && num>0 && num<1e9){
            fans.push_back(num);
        }
    }
    cout<<fans.size()<<"\n";
    for(auto i : fans){
        cout<<i<<" ";
    }
    cout<<"\n";



}

int main(){
 
     solve();
    
    return 0;
}