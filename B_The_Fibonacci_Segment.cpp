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
    int n;
    cin>>n;
    vector<int> vec(n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
    if(n<3){
        cout<<n<<"\n";
        return;
    }
    int max_len=2;
    int curr=2;
    for(int i=2;i<n;i++){
        if(vec[i]==vec[i-1]+vec[i-2]){
            curr++;
        }
        else{
            max_len=max(max_len,curr);
            curr=2;
        }
    }
    max_len=max(max_len,curr);
    cout<<max_len<<"\n";

}

int main(){
 
    solve();
    
    return 0;
}