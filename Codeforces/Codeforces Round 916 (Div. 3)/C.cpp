#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define int long long
#define debug(x) cerr << #x << ':' << x << ' '
using namespace std;
using LL = long long;

signed main(){
    int T = 1;
    cin >> T;
   while (T --){
        int n,k;
        cin >> n >> k;
        vector<int> a(n + 1), b(n + 1), pre(n + 1,0);
        for (int i = 1;i <= n;i ++){
            cin >> a[i];
            pre[i] = pre[i - 1] + a[i];
        }
        for (int i = 1;i <= n;i ++){
            cin >> b[i];
        }
        int mx = 0;
        int ans = 0;
        for (int i = 1;i <= min(n,k);i ++){
            mx = max(mx,b[i]);
            ans = max(ans,pre[i] + (k - i) * mx);
        }
        cout << ans << '\n';
    }
}