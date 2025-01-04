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
    
    vector<pair<int, int>> bottles(n);  // Each pair contains (a, b)
    unordered_multiset<int> openers;    // Stores all bottle openers (multiset for multiple entries)
    
    // Read bottles and record openers
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        bottles[i] = {a, b};
        
        // Add all openers (b), even if they match their own caps (a == b)
        openers.insert(b);
    }
    
    int count = 0;
    
    // Check each bottle if its cap type 'a' is openable by any other bottle
    for (int i = 0; i < n; ++i) {
        int a = bottles[i].first;
        int b = bottles[i].second;
        
        // If 'a' appears in openers more than once OR if a != b and 'a' appears once, it can be opened
        if (openers.count(a) == 0 || (a == b && openers.count(a) == 1)) {
            count++;
        }
    }
    
    cout << count << endl;
}

int main(){
  
    solve();
    return 0;
}