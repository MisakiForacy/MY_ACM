#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())
using namespace std;
using LL = long long;

int N = 2e5 + 10;

vector<LL> p, s(N, 0);

const LL inf = 1e15;

void Euler() {
    s[1] = 1;
    for (int i = 2;i < N;i ++) {
        if (!s[i]) p.push_back(i);
        for (int j = 0;j < siz(p) && p[j] * i < N;j ++) {
            s[p[j] * i] = 1;
            if (i % p[j] == 0) break;
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<LL> a(n + 1, 0), c(n + 1, 0), alls;
    for (int i = 1;i <= n;i ++) cin >> a[i], alls.push_back(a[i]);
    for (int i = 1;i <= n;i ++) cin >> c[i];
    sort(all(alls));
    alls.erase(unique(all(alls)), alls.end());
    int m = siz(alls);
    for (int i = 1;i <= n;i ++) a[i] = lower_bound(all(alls), a[i]) - alls.begin() + 1;
    vector<LL> dp(m + 1, c[1]);
    dp[a[1]] = 0;
    for (int i = 2;i <= n;i ++) {
        vector<LL> ndp(m + 1, inf);
        vector<LL> Min(m + 1, inf);
        Min[0] = dp[0];
        for (int j = 1;j <= m;j ++) Min[j] = min(Min[j - 1], dp[j]);
        for (int j = 0;j <= m;j ++) {
            if (a[i] != j)
                ndp[j] = Min[j] + c[i];
            else
                ndp[j] = Min[j];
        }
        // for (int j = 0;j <= m;j ++) cout << ndp[j] << ' ';
        // cout << '\n';
        dp = ndp;
    }
    LL ans = inf;
    for (int j = 0;j <= m;j ++) ans = min(ans, dp[j]);
    cout << ans << '\n';
}

int main() {
    // Euler();
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}