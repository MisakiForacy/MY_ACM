#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
using namespace std;
using LL = long long;
// 贪心：遍历状态的贪心
int main(){
    int T;
    cin >> T;
    while (T--){
        int n,m,v;
        cin >> n >> m >> v;
        vector<LL> a(n+1,0);
        vector<LL> pre(n+1,0), suf(n+2,0);
        vector<LL> pfx(n+1,0), sfx(n+2,0);
        for (int i=1;i<=n;i++) cin >> a[i];
        for (int i=1;i<=n;i++) pre[i] = pre[i-1] + a[i];
        for (int i=n;i>=1;i--) suf[i] = suf[i+1] + a[i];
        int l = 0, r = n+1;
        for (int i=1;i<=n;i++){
            if (pre[i] - pre[l] >= v){
                pfx[i] = pfx[i-1] + 1;
                l = i;
            } else{
                pfx[i] = pfx[i-1];
            }
        }
        for (int i=n;i>=1;i--){
            if (suf[i] - suf[r] >= v){
                sfx[i] = sfx[i+1] + 1;
                r = i;
            } else{
                sfx[i] = sfx[i+1];
            }
        }
        LL ans = -1;
        l = 0;
        for (int i=1;i<=n+1;i++){
            while (l <= n && sfx[i]+pfx[l]<m) l ++;
            if (l <= i){
                ans = max(pre[i-1]-pre[l],ans);
            }
        }
        cout << ans << '\n';
    }
}