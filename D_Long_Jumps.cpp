#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()

void solve() {
    int n, l, x, y;
    cin >> n >> l >> x >> y;
    vector<int> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }

    unordered_set<int> positions(vec.begin(), vec.end());
    bool has_x = false, has_y = false;

 
    for (int i = 0; i < n; i++) {
        if (positions.count(vec[i] + x)) has_x = true;
        if (positions.count(vec[i] + y)) has_y = true;
    }

    if (has_x && has_y) {
        
        cout << "0\n";
        return;
    }
    if (has_x) {
        cout << "1\n" << y << "\n";
        return;
    }
    if (has_y) {
        cout << "1\n" << x << "\n";
        return;
    }


  
     for (int i = 0; i < n; i++) {
        int current = vec[i];

        // Check adding a mark at `current + x` or `current - x`
        if (current + x <= l && (positions.count(current + x - y) || positions.count(current + x + y))) {
            cout << "1\n" << current + x << "\n";
            return;
        }
        if (current - x >= 0 && (positions.count(current - x - y) || positions.count(current - x + y))) {
            cout << "1\n" << current - x << "\n";
            return;
        }

        // Check adding a mark at `current + y` or `current - y`
        if (current + y <= l && (positions.count(current + y - x) || positions.count(current + y + x))) {
            cout << "1\n" << current + y << "\n";
            return;
        }
        if (current - y >= 0 && (positions.count(current - y - x) || positions.count(current - y + x))) {
            cout << "1\n" << current - y << "\n";
            return;
        }
    }


 
    cout << "2\n" << x << " " << y << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
