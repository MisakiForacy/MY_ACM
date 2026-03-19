#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n,k;
        cin >> n >> k;
        vector<LL> a(n+1);
        vector<LL> pre(n+1,0);
        for (int i=1;i<=n;i++) cin >> a[i];
        sort(a.begin()+1,a.end(),[&](int x,int y){
            return x > y;
        });
        for (int i=1;i<=n;i++){
            pre[i] = pre[i-1] + a[i];
        }
        LL ans = k;
        for (int i=1;i<=n;i++){
            if (pre[i] <= k){
                ans = min(ans,k-pre[i]);
            }
        }
        cout << ans << '\n';
    }
}