#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool backtrack(const string& s, int m, int diff, int last, vector<int>& sequence) {
    if (m == 0) return true; 

    for (int i = 1; i <= 10; ++i) {
        if (s[i - 1] == '1' && i != last && i > diff) {
            sequence.push_back(i); 
            if (backtrack(s, m - 1, i - diff, i, sequence)) return true;
            sequence.pop_back();  
        }
    }

    return false;  
}

int main() {
    string s;
    int m;
    cin >> s >> m;

    vector<int> sequence;
    if (backtrack(s, m, 0, 0, sequence)) {
        cout << "YES\n";
        for (int w : sequence) cout << w << " ";
        cout << endl;
    } else {
        cout << "NO\n";
    }

    return 0;
}
