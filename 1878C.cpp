#include<iostream>
#include<vector>
#include<iomanip>
#include<string.h>
#include<algorithm>
using namespace std;
int main(){
    int test;
    cin>>test;
    while(test--){
        long long n, x, k; 
		cin >> n >> x >> k;
		if(2*k>=x*(x+1) && 2*k<=n*(n+1)-(n-x)*(n-x+1)){ 
			cout << "YES\n";
		}
		else cout << "NO\n";
    }
    return 0;
}