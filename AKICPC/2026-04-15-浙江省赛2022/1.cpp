#include<bits/stdc++.h>
using namespace std;
int n,m,a[12345][2],mp[1005][1005],l=1;
int main(){
        freopen("seat.in","r",stdin);
        freopen("seat.out","w",stdout);
        cin>>n>>m;  
        for(int i=1;i<=n*m;i++){
                a[i][0]=i;
                cin>>a[i][1];
        }
        for(int i=1;i<=n*m;i++){
                for(int j=n*m;j>i;j--){
                        if(a[j][1]>a[j-1][1]) swap(a[j],a[j-1]);
                }
        }
        for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                        mp[i][j]=a[l++][0];
                        if(mp[i][j]==1){
                                cout<<i<<' '<<j;
                                break;}}
                i+=1;
                for(int j=m;j>=1;j--){
                        mp[i][j]=a[l++][0];
                        if(mp[i][j]==1){
                                cout<<i<<' '<<j;
                                break;}}
        }
    return 0;
}