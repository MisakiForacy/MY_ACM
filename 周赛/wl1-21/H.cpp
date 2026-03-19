#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), alls, dp(n + 1, 0);
    for (int i = 1;i <= n;i ++) cin >> a[i], alls.push_back(a[i]);
    sort(all(alls));
    alls.erase(unique(all(alls)), alls.end());
    for (int i = 1;i <= n;i ++) a[i] = lower_bound(all(alls), a[i]) - alls.begin() + 1;
    int mx = 0;
    for (int i = 1;i <= n;i ++) {
        dp[a[i]] = max(dp[a[i] - 1] + 1, dp[a[i]] + 1);
        mx = max(mx, dp[a[i]]);
    }
    cout << n - mx << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}