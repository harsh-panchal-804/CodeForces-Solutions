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
    string s;
    cin >> s;
    ll nb, ns, nc;
    cin >> nb >> ns >> nc;
    ll pb, ps, pc;
    cin >> pb >> ps >> pc;
    ll r;
    cin >> r;

    ll rb = count(s.begin(), s.end(), 'B');
    ll rs = count(s.begin(), s.end(), 'S');
    ll rc = count(s.begin(), s.end(), 'C');
    ll low = 0, high = 1e14, ans = 0;
    while (low <= high) {
        ll mid = low + (high - low) / 2;
        ll needed_b = max(0LL, rb * mid - nb);
        ll needed_s = max(0LL, rs * mid - ns);
        ll needed_c = max(0LL, rc * mid - nc);
        ll total_cost = needed_b * pb + needed_s * ps + needed_c * pc;

        if (total_cost <= r) {
            ans = mid; 
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << ans << "\n";
}

int main(){
    
    solve();
    
    return 0;
}