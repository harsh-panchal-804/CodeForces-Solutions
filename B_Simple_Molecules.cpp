#include <bits/stdc++.h>
#define ll long long
#define INF (1LL << 60)
#define inf 1 << 30
const long long mod = 1e9 + 7;
using namespace std;


vector<int> sieve(int n) {
    vector<bool> vec(n + 1, true);
    vec[0] = vec[1] = false;
    for (int i = 2; i <= n; i++) {
        if (vec[i]) {
            for (int j = 2 * i; j <= n; j += i) {
                vec[j] = false;
            }
        }
    }
    vector<int> ans;
    for (int i = 0; i <= n; i++) {
        if (vec[i]) {
            ans.push_back(i);
        }
    }
    return ans;
}

void solve() {
    int a, b, c;
    cin >> a >> b >> c;

    // Check if the total sum is odd, in which case it's impossible
    if ((a + b + c) % 2 != 0) {
        cout << "Impossible" << endl;
        return;
    }

    // Calculate p, q, r
    int p = (b + c - a) / 2;
    int q = (c + a - b) / 2;
    int r = (a + b - c) / 2;

    // Check if any of the values are negative, which makes it impossible
    if (p < 0 || q < 0 || r < 0) {
        cout << "Impossible" << endl;
    } else {
        cout << r << " " << p << " " << q << endl;
    }
}


int main() {
    solve();
    return 0;
}
