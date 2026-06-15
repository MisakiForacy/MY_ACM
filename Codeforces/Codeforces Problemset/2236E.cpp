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
    map<int, vector<int>> mp;
    for (int l = 1;l <= n;l ++) {
        for (int r = l;r <= n;r ++) {
            if (dp[l][r] == r - l + 1 && Mx[l][r] - Mi[l][r] == r - l) {
                mp[r - l + 1].push_back(Mi[l][r]);
            }
        }
    }
    for (auto &[k, v] : mp) sort(all(v));
    // for (auto &[k, v] : mp) {
    //     cout << k << ':' << '\n';
    //     for (auto x : v) cout << x << ' ';
    //     cout << '\n';
    // }
    for (int i = n / 2;i >= 1;i --) {
        for (int j = 0;j < siz(mp[i]);j ++) {
            if (*lower_bound(all(mp[i]), mp[i][j] + i) == mp[i][j] + i) {
                cout << i << '\n';
                return; 
            }
        }
    }
    cout << 0 << '\n';
    // cout << check(3) << ' ' << check(2) << '\n';
    // int lo = 0, hi = n / 2;
    // while (lo < hi) {
    //     int mid = lo + hi + 1 >> 1;
    //     if (check(mid)) 
    //         lo = mid;
    //     else 
    //         hi = mid - 1;
    // }
    // // cout << check(4) << '\n';
    // // if (!check(lo)) lo --;
    // cout << lo << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}
