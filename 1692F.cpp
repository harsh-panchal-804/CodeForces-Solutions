#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iomanip>
using namespace std;
void print(){
    int n;
        cin>>n;
        vector<int> count(10,0);
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            count[x%10]++;
        }
        vector<int> nums;
        for(int i=0;i<10;i++){
            for(int j=0;j<min(3,count[i]);j++){
                nums.push_back(i);
            }
        }
        int s=nums.size();
        for(int i=0;i<s;i++){
            for(int j=i+1;j<s;j++){
                for(int k=j+1;k<s;k++){
                    if((nums[i]+nums[j]+nums[k]) %10==3){
                        cout<<"YES"<<endl;
                        return;
                        
                    }
                }
            }
        }
        cout<<"NO"<<endl;
        return;
    
}
int main(){
    int test;
    cin>>test;
    for(int t=0;t<test;t++){
        print();
    }
    
    return 0;
}