#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    if (n > m + 1 || m > 2 * n + 2) {
        cout << "-1\n";
        return 0;
    }
    
    string result = "";
    while (m > 0 || n > 0) {
        if (m > n) {
            if (m > 1) {
                result += "11";
                m -= 2;
            } else {
                result += "1";
                m -= 1;
            }
            if (n > 0) {
                result += "0";
                n -= 1;
            }
        } else {
            if (n > 0) {
                result += "0";
                n -= 1;
            }
            if (m > 0) {
                result += "1";
                m -= 1;
            }
        }
    }
    
    cout << result << "\n";
    return 0;
}
