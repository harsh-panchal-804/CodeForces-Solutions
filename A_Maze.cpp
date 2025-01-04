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
const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};

void dfs(int x, int y, vector<string>& grid, vector<vector<bool>>& visited, vector<pair<int, int>>& cells) {
    int n = grid.size(), m = grid[0].size();
    stack<pair<int, int>> s;
    s.push({x, y});
    visited[x][y] = true;

    while (!s.empty()) {
      
        int cx=s.top().first;
        int cy=s.top().second;
        s.pop();
        cells.push_back({cx, cy});
        for (int d = 0; d < 4; ++d) {
            int nx = cx + dx[d], ny = cy + dy[d];
            if (nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] == '.' && !visited[nx][ny]) {
                visited[nx][ny] = true;
                s.push({nx, ny});
            }
        }
    }
}



void solve(){
    int n, m, k;
    cin >> n >> m >> k;

    vector<string> grid(n);
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<pair<int, int>> cells;

    // Find the first open cell to start DFS
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == '.') {
                dfs(i, j, grid, visited, cells);
                break;
            }
        }
        if (!cells.empty()) break;
    }

    // Number of cells to leave open
    int leave_open = cells.size() - k;

    // Mark cells to block
    for (int i = 0; i < (int)cells.size(); ++i) {
       
        int x=cells[i].first;
        int y=cells[i].second;
        if (i < leave_open) {
            grid[x][y] = '.'; // Leave as part of connected component
        } else {
            grid[x][y] = 'X'; // Block this cell
        }
    }

    // Output the resulting grid
    for (int i = 0; i < n; ++i) {
        cout << grid[i] << endl;
    }

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
