#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
const long long mod = 1e9 + 7;
#define INF (1LL << 60)
#define inf (1 << 30)
#define all(x) (x).begin(), (x).end()

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(lld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);

template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);

template <class T, class V> void _print(pair <T, V> p) {
    cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";
}
template <class T> void _print(vector <T> v) {
    cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";
}
template <class T> void _print(set <T> v) {
    cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";
}
template <class T> void _print(multiset <T> v) {
    cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";
}
template <class T, class V> void _print(map <T, V> v) {
    cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";
}

const double PI = acos(-1);

void solve(){
    int n; 
    cin >> n; // Input the number of points
    vector<double> angles(n);

    // Step 1: Read points and calculate angles
    for (int i = 0; i < n; ++i) {
        double x, y;
        cin >> x >> y; // Input the coordinates of the point
        angles[i] = atan2(y, x); // Calculate the angle of the point
        if (angles[i] < 0) angles[i] += 2 * PI; // Normalize angle to [0, 2π)
    }

    // Step 2: Sort the angles
    sort(angles.begin(), angles.end());

    // Step 3: Calculate maximum angular gap
    double max_gap = 0;
    for (int i = 1; i < n; ++i) {
        max_gap = max(max_gap, angles[i] - angles[i - 1]); // Gap between consecutive angles
    }

    // Step 4: Consider the wrap-around gap
    max_gap = max(max_gap, 2 * PI - (angles[n - 1] - angles[0]));

    // Step 5: Calculate the maximum viewable angle
    double max_view_angle = 2 * PI - max_gap;

    // Output the result in degrees
    cout <<setprecision(10) <<fixed << max_view_angle * 180 / PI << endl;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("Error.txt", "w", stderr);
    #endif
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int test=1;
    // cin>>test;
    while(test--){
         solve();
    }
    
    return 0;
}
