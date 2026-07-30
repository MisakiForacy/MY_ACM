#include <bits/stdc++.h>

using namespace std;

using LL = long long;

// abbaabba
// bbaabbaa 

void solve() {
    int n, d;
    cin >> n >> d;
    string s;
    cin >> s;
    s = ' ' + s;
    vector<int> f(n + 1);
    for (int i = 1;i <= n;i ++) f[i] = i;
    auto find = [&](auto find, int x) -> int {
        return (f[x] == x ? f[x] : f[x] = find(find, f[x]));
    };
    auto merge = [&](int x, int y) -> void {
        x = find(find, x);
        y = find(find, y);
        if (x == y) return;
        if (x < y) swap(x, y);
        f[x] = y;
    };
    int cnt_ = 0;
    for (int l = 1;l <= n;l += d) {
        int r = n - l + 1;
        for (int i = 1;i <= n - 1;i ++) {
            // cout << l << ' ' << r << '\n';
            cnt_ ++;
            if (find(find, l) == find(find, r)) break;
            merge(l, r);
            l = (l + d - 1) % n + 1;
            r = (r + d - 1) % n + 1;
        }
    }
    unordered_map<int, map<char, int>> mp;
    unordered_map<int, int> cnt;
    for (int i = 1;i <= n;i ++) mp[find(find, i)][s[i]] ++, cnt[find(find, i)] ++;
    int ans = 0;
    for (auto [k, v] : mp) {
        int mx = 0;
        for (auto [c, vv] : v) {
            mx = max(mx, vv);
        }
        ans += cnt[k] - mx;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}
