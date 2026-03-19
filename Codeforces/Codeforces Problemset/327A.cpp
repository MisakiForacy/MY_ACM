#include <bits/stdc++.h>
#define N 1005
using namespace std;
int main(){
    int n,cnt,ans;
    cin >> n;
    cnt = ans = 0;
    int a[N],b[N];
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    for (int i=1;i<=n;i++){
        cin >> a[i];
        if (a[i]){
            cnt ++;
            b[i] = max(0,b[i-1]-1);
        } else{
            b[i] = b[i-1]+1;
            ans = max(ans,b[i]);
        }
    }
    if (cnt==n){
        cnt --;
    }
    cout << ans + cnt << '\n';
}