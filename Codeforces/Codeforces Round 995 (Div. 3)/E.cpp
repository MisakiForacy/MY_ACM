#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        LL n,k;
        cin >> n >> k;
        vector<LL> a(n),b(n);
        for (int i=0;i<n;i++) cin >> a[i];
        for (int i=0;i<n;i++) cin >> b[i];
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        LL ans = 0;
        for (int i=0;i<n;i++){
            LL t1 = lower_bound(a.begin(),a.end(),a[i]) - a.begin();
            LL t2 = lower_bound(b.begin(),b.end(),a[i]) - b.begin();
            LL cp = t1 - t2;
            if (cp <= k){
                ans = max(ans,(n-t2) * a[i]);
            }
            t1 = lower_bound(a.begin(),a.end(),b[i]) - a.begin();
            t2 = lower_bound(b.begin(),b.end(),b[i]) - b.begin();
            cp = t1 - t2;
            if (cp <= k){
                ans = max(ans,(n-t2) * b[i]);
            }
        }
        cout << ans << '\n';
    }
}