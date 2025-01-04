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
    int n, m;
    cin >> n >> m;

    vector<int> colors(n + 1, -1); 
    
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

    
        set<int> used_colors;
        if (colors[a] != -1) used_colors.insert(colors[a]);
        if (colors[b] != -1) used_colors.insert(colors[b]);
        if (colors[c] != -1) used_colors.insert(colors[c]);

        
        int color = 1;  
        if (colors[a] == -1) {
            while (used_colors.count(color)) color++;
            colors[a] = color;
            used_colors.insert(color);
        }
        color = 1;  
        if (colors[b] == -1) {
            while (used_colors.count(color)) color++;
            colors[b] = color;
            used_colors.insert(color);
        }
        color = 1;  
        if (colors[c] == -1) {
            while (used_colors.count(color)) color++;
            colors[c] = color;
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << colors[i] << " ";
    }
    cout << "\n";


}

int main(){
   
    solve();
    
    return 0;
}