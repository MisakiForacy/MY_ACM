#include <bits/stdc++.h>
//an=2(2^(n-1)+(-1)^(n-2))
using namespace std;
int n,a[54321],ans,cnt[1234];
int main(){
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++){
                int c=0;
                memset(cnt,0,sizeof(cnt));
                for(int j=1;j<=i;j++){
                        c+=a[j];
                        cnt[j]=c;
                }
                sort(cnt+1,cnt+1+i);
                ans=max(ans,cnt[i]);
        }cout<<ans;
    return 0;
}