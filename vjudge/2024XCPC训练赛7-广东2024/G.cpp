#include<iostream>
#define int long long
using namespace std;
signed main(){
    int T;cin>>T;
    while(T--){
        int x,y;cin>>x>>y;
        int ans=1;
        for(int i=1;i<=1e6;i++){
            int a=(x+i-1)/i*i;
            int b=a+i;
            if(b<=y) ans=max(ans,i);
            
            int m=y/i;
            if(m==0) continue;
            a=(x+m-1)/m*m;
            b=a+m;
            if(b<=y) ans=max(ans,m);
        }
        cout<<ans<<endl;
    }
}