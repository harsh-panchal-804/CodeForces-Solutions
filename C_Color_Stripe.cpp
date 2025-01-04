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
#define debug(x)       \
    cerr << #x << " "; \
    _print(x);         \
    cerr << endl;
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

template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);

template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);

template <class T, class V>
void _print(pair<T, V> p)
{
    cerr << "{";
    _print(p.first);
    cerr << ",";
    _print(p.second);
    cerr << "}";
}
template <class T>
void _print(vector<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(set<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(multiset<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int a=0, b=0;
    if (k == 2)
    {
        for (int i = 0; i < n; i++)
        {
            if (s[i] - 'A' != i % 2)
                a++;
            else
                b++;
        }
        int mn = min(a, b);
        cout << mn << "\n";
        if (a < b)
        {
            for (int i = 0; i < n; i++)
            {
                cout << char('A' + i % 2);
              
            }
              cout<<"\n";
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                cout << char('A' + 1 - i % 2);
            }
                cout<<"\n";
        }
        return;
    }

    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        if (s[i] == s[i - 1])
        {
            for (int j = 1; j <= k; j++)
            {
                char ch = 'A' + (j - 1);
                bool flag = false;
                if (i == n - 1)
                {
                    if (ch != s[i - 1])
                    {
                        s[i] = ch;
                        flag = true;
                    }
                }
                else
                {
                    if (ch != s[i - 1] && ch != s[i + 1])
                    {
                        s[i] = ch;
                        flag = true;
                    }
                }

                if (flag)
                    break;
            }
            ans++;
        }
    }
    cout << ans << "\n";
    cout << s << "\n";
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int test = 1;
    // cin>>test;
    while (test--)
    {
        solve();
    }

    return 0;
}
