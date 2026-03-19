#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
using namespace std;
using LL = long long;
int main(){
    int T;
    cin >> T;
    while (T--){
        LL n;
        cin >> n;
        vector<LL> a(n+1,0);
        for (int i=1;i<=n;i++){
            cin >> a[i];
        }
        sort(a.begin(),a.end());
        LL ans = LLONG_MAX;
        LL id = n;
        for (int i=n-2;i>=1;i--){
            if (a[i] + a[i+1] <= a[id]){
                ans = min(ans,n-id+i);
                id = lower_bound(all(a),a[i]+a[i+1])-a.begin()-1;
            }
        }
        ans = min(ans,n-id);
        cout << ans << '\n';
    }
}