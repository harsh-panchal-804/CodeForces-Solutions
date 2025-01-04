#include<iostream>
#include<vector>
#include<iomanip>
#include<string.h>
#include<algorithm>
using namespace std;

int score[10][10] = {
	{1,1,1,1,1,1,1,1,1,1},
	{1,2,2,2,2,2,2,2,2,1},
	{1,2,3,3,3,3,3,3,2,1},
	{1,2,3,4,4,4,4,3,2,1},
	{1,2,3,4,5,5,4,3,2,1},
	{1,2,3,4,5,5,4,3,2,1},
	{1,2,3,4,4,4,4,3,2,1},
	{1,2,3,3,3,3,3,3,2,1},
	{1,2,2,2,2,2,2,2,2,1},
	{1,1,1,1,1,1,1,1,1,1}
};
void solve(){
    int ans=0;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            char a;
            cin>>a;
            if(a=='X') ans+= score[i][j];
        }
    }
    cout<<ans<<endl;
}
int main(){
    int test;
    cin>>test;
    for(int i=0;i<test;i++){
        solve();
    }
    return 0;
}