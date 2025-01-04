#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    int t, x, y, x1, y1;
    cin >> t >> x >> y >> x1 >> y1;
    string wind;
    cin >> wind;

    int dx = x1 - x;  
    int dy = y1 - y; 

    for (int i = 0; i < t; ++i) {
        if (dx > 0 && wind[i] == 'E') {
            dx--; 
        }
        if (dx < 0 && wind[i] == 'W') {
            dx++;  
        }
        if (dy > 0 && wind[i] == 'N') {
            dy--; 
        }
        if (dy < 0 && wind[i] == 'S') {
            dy++;  
        }
        
       
        if (dx == 0 && dy == 0) {
            cout << i + 1 << endl; 
            return;
        }
    }

    cout << -1 << endl;
    return;
}

int main() {
    solve();
    return 0;
}
