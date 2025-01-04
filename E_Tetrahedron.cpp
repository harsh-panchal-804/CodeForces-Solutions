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

void multiplyMatrices(int A[4][4], int B[4][4], int result[4][4]) {
    int temp[4][4] = {0};
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            temp[i][j] = 0;
            for (int k = 0; k < 4; ++k) {
                temp[i][j] = (temp[i][j] + 1LL * A[i][k] * B[k][j]) % mod;
            }
        }
    }
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            result[i][j] = temp[i][j];
        }
    }
}

void matrixExponentiation(int matrix[4][4], int power, int result[4][4]) {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            result[i][j] = (i == j) ? 1 : 0;
        }
    }
    while (power > 0) {
        if (power % 2 == 1) {
            int temp[4][4];
            multiplyMatrices(result, matrix, temp);
            for (int i = 0; i < 4; ++i) {
                for (int j = 0; j < 4; ++j) {
                    result[i][j] = temp[i][j];
                }
            }
        }
        int temp[4][4];
        multiplyMatrices(matrix, matrix, temp);
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                matrix[i][j] = temp[i][j];
            }
        }
        power /= 2;
    }
}


void solve(){
    int n;
    cin>>n;
    int matrix[4][4]={
        {0,1,1,1},
        {1,0,1,1},
        {1,1,0,1},
        {1,1,1,0},
    };
    int result[4][4];
    matrixExponentiation(matrix,n,result);
    cout<<result[3][3];
    
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("Error.txt", "w", stderr);
    #endif

    int test=1;
    // cin>>test;
    while(test--){
         solve();
    }
    
    return 0;
}
