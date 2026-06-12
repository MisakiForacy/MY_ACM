#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1, -1), dp(n + 1, 0);
    for (int i = 1;i <= n;i ++) cin >> a[i];
    for (int i = 1;i <= n;i ++) {
        if (a[i] - a[i - 1] == 1) {
            dp[i] = dp[i - 1] + 1;
        }
    }
    auto check = [&](int x) -> int {
        int ok = 0;
        for (int i = x;i <= n - x;i ++) {
            int mid = a[i];
            if (dp[i] < x) continue;
            for (int j = i + 1;j <= n - x + 1;j ++) {
                if (a[j] == mid + 1 && dp[j + x - 1] >= x) {
                    ok = 1;
                }
            }
        }
        for (int i = x;i <= n - x;i ++) {
            int mid = a[i] - x + 1;
            if (dp[i] < x) continue;
            for (int j = i + x;j <= n;j ++) {
                if (a[j] == mid - 1 && dp[j] >= x) {
                    ok = 1;
                } 
            }
        }
        return ok;
    };
    int lo = 0, hi = n / 2;
    while (lo < hi) {
        int mid = lo + hi >> 1;
        if (check(mid)) 
            lo = mid + 1;
        else 
            hi = mid;
    }
    cout << check(4) << '\n';
    if (!check(lo)) lo --;
    cout << lo << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}