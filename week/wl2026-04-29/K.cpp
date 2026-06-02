#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

#define x first 
#define y second 

using namespace std;
using LL = long long;

const int N = 2e5 + 5;

const LL mod = 998244353;

LL a[N], p10[11], len[N];

unordered_map<LL, LL> mp[11];

void solve() {
    LL n, k, ans = 0;
    cin >> n >> k;
    p10[0] = 1;
    for (int i = 1;i <= 10;i ++) p10[i] = p10[i - 1] * 10 % k;
    for (int i = 1;i <= n;i ++) cin >> a[i];
    for (int i = 1;i <= n;i ++) {
        LL tp = a[i];
        for (int j = 1;j <= 10;j ++) {
            mp[j][a[i] % k * p10[j] % k] ++;
            if (tp) len[i] ++, tp /= 10;
        }
        a[i] %= k;
    }
    for (int i = 1;i <= n;i ++) {
        if (!mp[len[i]].count((k - a[i] % k) % k)) continue;
        ans += mp[len[i]][(k - a[i] % k) % k];
        if ((a[i] + a[i] * p10[len[i]]) % k == 0) ans --;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}