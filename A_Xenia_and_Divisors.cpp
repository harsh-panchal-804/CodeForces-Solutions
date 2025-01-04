#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<int> vec(8, 0);
    
    
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        vec[x]++;
    }
    
  
    if (vec[5] > 0 || vec[7] > 0) {
        cout << -1 << "\n";
        return;
    }
    
   
    int numTriplets = vec[1]; 
    if (vec[1] != vec[2] + vec[3] || vec[1] != vec[4] + vec[6] || vec[3] > vec[6]) {
        cout << -1 << "\n";
        return;
    }

    while (vec[4] > 0) {
        cout << "1 2 4\n";
        vec[1]--; vec[2]--; vec[4]--;
    }
    
   
    while (vec[6] > 0 && vec[2] > 0) {
        cout << "1 2 6\n";
        vec[1]--; vec[2]--; vec[6]--;
    }
    
  
    while (vec[6] > 0 && vec[3] > 0) {
        cout << "1 3 6\n";
        vec[1]--; vec[3]--; vec[6]--;
    }
}

int main() {
    solve();
    return 0;
}
