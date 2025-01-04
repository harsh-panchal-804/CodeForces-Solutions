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
    cin >> n;
    vector<int> p(n);
    int count_fixed = 0;
    bool can_swap_for_two = false;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        if (p[i] == i) {
            count_fixed++;  
        }
    }

    
    for (int i = 0; i < n; i++) {
        if (p[i] != i && p[p[i]] == i) {
            can_swap_for_two = true;  
            break;
        }
    }

    if (count_fixed == n) {
     
        cout << n << endl;
    } else if (can_swap_for_two) {
       
        cout << count_fixed + 2 << endl;
    } else {
     
        cout << count_fixed + 1 << endl;
    }


}

int main(){
  
     solve();
    
    return 0;
}