#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define debug(x) cerr << #x << ':' << x << ' '
using namespace std;
using LL = long long;
const LL inf = LLONG_MAX;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --){
        LL n,k,d;
        cin >> n >> k >> d;
        LL ans = 0;
        vector<LL> a(n + 1), v(k + 1);
        vector<LL> diff(n + 2,0);
        for (int i = 1;i <= n;i ++) cin >> a[i];
        for (int i = 1;i <= k;i ++) cin >> v[i];
        for (int i = 1;i <= n;i ++){
            if (a[i] == i){
                ans += 1;
            }
        }
        ans += (d - 1) / 2;
        // cout << ans << '\n';
        for (int i = 1;i <= min(n * 2,d - 1);i ++){
            diff[1] ++, diff[v[(i - 1)%k + 1] + 1] --;
            LL c = 0, s = 0;
            for (int j = 1;j <= n;j ++){
                s += diff[j];
                if (a[j] + s == j) c ++;
            }
            ans = max(ans, c + (d - i - 1) / 2);
            // cout << (i - 1) % k + 1 << "*" << diff[v[(i - 1) % k + 1] + 1] << '\n';
            // cout << "ok\n";
            // cout << c + (d - i - 1) / 2 << '\n';
        }
        cout << ans << '\n';
    }
}