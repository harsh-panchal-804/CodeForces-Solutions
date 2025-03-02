#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long mod = 1e9 + 7;

void solve() {
    ll n;
    cin >> n;
    vector<ll> vec(n);
    unordered_map<ll, ll> mp;

    // Read input and populate map
    for (ll i = 0; i < n; i++) {
        cin >> vec[i];
        if (vec[i] != -1) {
            if (mp[vec[i]] >= 1) {
                cout << 0 << "\n";
                return;
            }
            mp[vec[i]]++;
        }
    }

    // If there are no -1, valid arrangement is already given
    if (count(vec.begin(), vec.end(), -1) == 0) {
        cout << 1 << "\n";
        return;
    }

    ll ans = 1;

    // Iterate to calculate possible replacements for -1
    for (ll i = 0; i < n; i++) {
        if (vec[i] == -1) {
            ll lower = 1; // Minimum possible replacement
            ll upper = INT_MAX; // Maximum possible replacement

            // Calculate lower bound based on previous element
            if (i > 0 && vec[i - 1] != -1) {
                lower = max(lower, vec[i - 1] + 1);
            }

            // Calculate upper bound based on next element
            if (i < n - 1 && vec[i + 1] != -1) {
                upper = min(upper, vec[i + 1] - 1);
            }

            if (lower > upper) {
                cout << 0 << "\n";
                return;
            }

            // Multiply possible valid numbers for this -1
            ans = (ans * (upper - lower + 1)) % mod;
        }
    }

    cout << ans << "\n";
}

int main() {
    int test;
    cin >> test;
    while (test--) {
        solve();
    }
    return 0;
}
