
// int dist(int point,vector<int> lamps){ doesnt work as street is continous not discrete like heaters in leetcode
//     int dist=-1;
//     int l=0;
//     int r=lamps.size()-1;
//     while(l<=r){
//         int mid=(l+r)/2;
//         ans=min(ans,abs(lamps[mid]-point));
//         if(point < lamps[mid]){
//             ans=min(ans,abs(lamps[mid]-point));
//             r=mid-1;
//         }
//         else{
//             l=mid+1;
//         }
//     }
//     return ans;
// }
#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iomanip>
using namespace std;
int main(){
    int n,l;
    cin>>n>>l;
    vector<int> lamps(n);
    
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        lamps[i]=x;
    }
    sort(lamps.begin(),lamps.end());
    double ans=2*max(lamps[0],l-lamps[n-1]);
    for(int i=0;i<n-1;i++){
        ans=max(ans,(double)lamps[i+1]-lamps[i]);
    }
    cout<<setprecision(10)<<ans/2<<endl;

    
    
    return 0;
}