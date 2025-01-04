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
int func(vector<int>&vec,int a){
    auto it = lower_bound(vec.begin(), vec.end(), a);
    if (it == vec.begin()) {
        return -1; 
    }
    return (--it)-vec.begin();
}
void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    n=s.size()/2;
    vector<int> vec1;
    vector<int> vec2;
    for(int i=0;i<n;i++){
        vec1.push_back(s[i]-'0');
    }
    multiset<int> set2;
    for(int i=n;i<2*n;i++){
        vec2.push_back(s[i]-'0');
    }
    sort(vec1.begin(),vec1.end());
    sort(vec2.begin(),vec2.end());
    vector<int> vec3=vec1;
    vector<int> vec4=vec2;
    bool flag1=true;///strictly greater
    for(auto i :vec1){
        ///cout<<i<<' ';
        auto find=upper_bound(vec2.begin(),vec2.end(),i);
        if(find==vec2.end())flag1=false;
        else{
            vec2.erase(find);
        }
    }
    bool flag2=true;
    for(auto i : vec3){
        int find=func(vec4,i);
        if(find==-1)flag2=false;
        else vec4.erase(find+vec4.begin());
    }
    ///cout<<flag1<<' '<<flag2;
    if(flag1||flag2)cout<<"YES"<<'\n';
    else cout<<"NO"<<"\n";

}

int main(){
    
    solve();
    
    return 0;
}
