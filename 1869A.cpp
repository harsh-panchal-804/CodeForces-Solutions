#include<iostream>
#include<vector>
#include<iomanip>
#include<string.h>
#include<algorithm>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int>vec(n);
    for(int i=0;i<n;i++)cin>>vec[i];
    if (n & 1) {
		cout << "4" << '\n';
		cout << "1 " << n - 1 << '\n';
		cout << "1 " << n - 1 << '\n';
		cout << n - 1 << ' ' << n << '\n';
		cout << n - 1 << ' ' << n << '\n';
	} else {
		cout << "2" << '\n';
		cout << "1 " << n << '\n';
		cout << "1 " << n << '\n';
	}
	return;
}
int main(){
    int test;
    cin>>test;
    while(test--){
        solve();
    }
    return 0;
}