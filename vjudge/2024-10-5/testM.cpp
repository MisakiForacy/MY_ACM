#include<iostream>
#define int long long
using namespace std;
const int MAXN=3e5+5;
int n,a[MAXN],b[MAXN];
int check(int t){
    int cnt=0;
    for(int i=0;i<n;i++) if(a[i]>=t) cnt++;
    if(cnt>=(n+1)/2) return 1;

    int cnt2=0,now=0;
    for(int i=0;i<n;i++){
        if(a[i]<t&&b[i]>=t) now++;
        else if(a[i]>=t&&b[i]<t) now--;
        cnt2=max(cnt2,now);
        now=max(now,0ll);
    }
    if(cnt+cnt2>=(n+1)/2) return 1;
    return 0;

}
signed main(){
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i]>>b[i];
    int l=0,r=1e9;
    int ans=a[0];
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid)){
            ans=mid;
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    cout<<ans<<'\n';
}//