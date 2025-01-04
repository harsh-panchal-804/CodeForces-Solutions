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

template <typename T, typename Combine = function<T(const T&, const T&)>>
class SegmentTree {
private:
    vector<T> tree;
    int n;
    T neutral;          // Neutral element for the combine operation
    Combine combine;    // The function to combine two elements

    void build(const vector<T>& arr, int node, int start, int end, int level) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            int leftChild = 2 * node + 1;
            int rightChild = 2 * node + 2;
            build(arr, leftChild, start, mid, level + 1);
            build(arr, rightChild, mid + 1, end, level + 1);
            if (level % 2 == 0) {
                tree[node] = tree[leftChild] ^ tree[rightChild]; // OR at odd levels
            } else {
                tree[node] = tree[leftChild] | tree[rightChild]; // XOR at even levels
            }
        }
    }

    void update(int node, int start, int end, int idx, const T& value, int level) {
        if (start == end && start == idx) {
            tree[node] = value;
        } else {
            int mid = (start + end) / 2;
            int leftChild = 2 * node + 1;
            int rightChild = 2 * node + 2;
            if (idx <= mid) update(leftChild, start, mid, idx, value, level + 1);
            else update(rightChild, mid + 1, end, idx, value, level + 1);
            if (level % 2 == 0) {
                tree[node] = tree[leftChild] ^ tree[rightChild]; // OR at odd levels
            } else {
                tree[node] = tree[leftChild] | tree[rightChild]; // XOR at even levels
            }
        }
    }

    T query(int node, int start, int end, int l, int r) const {
        if (r < start || end < l) {
            return neutral;
        }
        if (l <= start && end <= r) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        int leftChild = 2 * node + 1;
        int rightChild = 2 * node + 2;
        T leftResult = query(leftChild, start, mid, l, r);
        T rightResult = query(rightChild, mid + 1, end, l, r);
        return combine(leftResult, rightResult);
    }

public:
    SegmentTree(const vector<T>& arr, T neutralElement, Combine combineFunc)
        : n(arr.size()), neutral(neutralElement), combine(combineFunc) {
        tree.assign(4 * n + 100, neutral);
        build(arr, 0, 0, n - 1, 1);
    }

    void update(int idx, const T& value) {
        update(0, 0, n - 1, idx, value, 1);
    }

    T query(int l, int r) const {
        return query(0, 0, n - 1, l, r);
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    n = (1 << n);
    vector<int> vec(n);
    for (int i = 0; i < n; i++) cin >> vec[i];
    SegmentTree<int> tree(vec, 0, [](int a, int b) {
        return a + b;
    });
    while (m--) {
        int p, b;
        cin >> p >> b;
        p--;
        tree.update(p, b);
        cout << tree.query(0, n - 1) << "\n";
    }
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("Error.txt", "w", stderr);
    #endif
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int test = 1;
    // cin >> test;
    while (test--) {
        solve();
    }
    return 0;
}
