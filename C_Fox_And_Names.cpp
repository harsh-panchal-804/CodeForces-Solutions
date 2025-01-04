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

template <class T, class V> void _print(pair <T, V> p) {
    cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";
}
template <class T> void _print(vector <T> v) {
    cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";
}
template <class T> void _print(set <T> v) {
    cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";
}
template <class T, class V> void _print(map <T, V> v) {
    cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";
}

void solve() {
    int n;
    cin >> n;

    vector<string> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }

    unordered_map<char, set<char>> graph;
    vector<int> indegree(26, 0);
    vector<bool> present(26, false); // To mark characters that appear in strings

    // Process each pair of consecutive strings
    for (int i = 0; i < n - 1; i++) {
        string l = vec[i];
        string r = vec[i + 1];
        bool found = false;
        for (int k = 0; k < min(l.size(), r.size()); k++) {
            char x = l[k], y = r[k];
            present[x - 'a'] = true;
            present[y - 'a'] = true;
            if (x != y) {
                if (graph[x].insert(y).second) {
                    indegree[y - 'a']++;
                }
                found = true;
                break;
            }
        }
        if (!found && l.size() > r.size()) {
            cout << "Impossible\n";
            return;
        }
    }

    // Include all characters that appeared in the strings
    for (const string &s : vec) {
        for (char c : s) {
            present[c - 'a'] = true;
        }
    }

    // Topological Sort (Kahn's Algorithm)
    queue<char> q;
    string result = "";
    for (int i = 0; i < 26; i++) {
        if (present[i] && indegree[i] == 0) {
            q.push('a' + i);
        }
    }

    while (!q.empty()) {
        char node = q.front();
        q.pop();
        result += node;
        for (char neighbor : graph[node]) {
            indegree[neighbor - 'a']--;
            if (indegree[neighbor - 'a'] == 0) {
                q.push(neighbor);
            }
        }
    }

    // Check if there's a cycle
    if (result.size() != count(present.begin(), present.end(), true)) {
        cout << "Impossible\n";
    } else {
        for(int i=0;i<26;i++){
            if(!present[i]){
                result += ('a'+i);
            }
        }
        cout<<result<<"\n";
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
