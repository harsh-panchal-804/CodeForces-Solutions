#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k,bpos,spos;
        int bscore=0;
        int sscore=0;
        
        cin>>n;
        cin>>k;
        vector<int> p(n);
        vector<int> a(n);
        cin>>bpos;
        cin>>spos;
        for(int j=0;j<n;j++){
            int x;
            cin>>x;
            p[j]=x;
        }
        for(int l=0;l<n;l++){
            int x;
            cin>>x;
            a[l]=x;
        }
        for(int i=0;i<k-1;i++){
            //bodyas turn
            bscore+=a[bpos-1];
            //2 choices
            int nextpos=p[bpos-1];
            if(a[nextpos]>a[bpos-1]){//move 
                bpos=nextpos;
            }
            sscore+=a[spos-1];
            int nextspos=p[spos-1];
            if(a[nextspos]>a[spos-1]){
                spos=nextspos;
            }             
        }
        if(bscore>sscore){
            cout<<"Bodya"<<endl;
        }
        else if(bscore<sscore) cout<<"Sasha"<<endl;
        else cout<<"Draw"<<endl;   
    }
    
    return 0;
}