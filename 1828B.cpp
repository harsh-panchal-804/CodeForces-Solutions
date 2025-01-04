#include<iostream>
#include<vector>
#include<iomanip>
#include<string.h>
#include<algorithm>
using namespace std;
int main(){
    int test;
    cin>>test;
    while (test--) {
    	int n, res = 0;
    	cin >> n;
    	for (int i = 1; i <= n; i++) {
    		int x; cin >> x;
    		res = __gcd(res, abs(x - i));
    	}
    	cout << res << "\n";
    }
    
        
    
    return 0;
}