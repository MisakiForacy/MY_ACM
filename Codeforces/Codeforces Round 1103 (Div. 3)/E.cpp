#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

#define lowbit(x) ((x) & (-x))

using namespace std;
using LL = long long;

const LL inf = 1e15;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1, -1);
    vector<vector<int>> dp(n + 1, vector<int> (n + 1, 1));
    vector<vector<int>> Mi(n + 2, vector<int>(n + 2));
    vector<vector<int>> Mx(n + 2, vector<int>(n + 2));
    for (int i = 1;i <= n;i ++) cin >> a[i];
    for (int l = 1;l <= n;l ++) {
        vector<int> p(n + 1, 0);
        int d = 0;
        Mi[l][l] = Mx[l][l] = a[l];
        for (int r = l;r <= n;r ++) {
            if (p[a[r]] ++ == 0) d ++;
            dp[l][r] = d;
            if (r == l) continue;
            Mi[l][r] = min(Mi[l][r - 1], a[r]);
            Mx[l][r] = max(Mx[l][r - 1], a[r]);
        }
    }
    // cout << Mi[1][n] << '\n';
    // cout << "ok\n";
    auto check = [&](int x) -> int {
        int ok = 0;
        for (int i = x;i <= n;i ++) {
            int l = i - x + 1, r = i;
            if (l > r) continue;
            if (r - l + 1 != dp[l][r]) continue;
            int mi = Mi[l][r], mx = Mx[l][r];
            // cout << l << ' ' << r << ' ' << mx << ' ' << mi << '\n';
            if (mx - mi + 1 != dp[l][r]) continue;
            for (int j = x;j <= n;j ++) {
                int ll = j - x + 1, rr = j;
                if (ll > rr) continue;
                if (!(r < ll || rr < l)) continue;
                if (rr - ll + 1 != dp[ll][rr]) continue;
                int mii = Mi[ll][rr], mxx = Mx[ll][rr];
                if (!(mii == mx + 1 || mxx == mi - 1)) continue;
                if (mxx - mii + 1 != dp[ll][rr]) continue;
                ok = 1;
            }
        }
        return ok;
    };
    int lo = 0, hi = n / 2;
    while (lo < hi) {
        int mid = lo + hi + 1 >> 1;
        if (check(mid)) 
            lo = mid;
        else 
            hi = mid - 1;
    }
    // cout << check(4) << '\n';
    // if (!check(lo)) lo --;
    cout << lo << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}