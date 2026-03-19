#include <bits/stdc++.h>

#define x first 
#define y second 

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;

void solve() {
    LL n, k;
    cin >> n >> k;
    vector<LL> use;
    for (int i = 0;i < (1LL << 14);i ++) {
        int cnt = 0;
        for (int j = 0;j <= 14;j ++) {
            if (i >> j & 1) cnt ++;
        }
        if (cnt == k) use.push_back(i);
    }
    // cout << siz(use) << '\n';
    vector<LL> p(n + 1);
    // map<LL, int> mp;
    vector<int> mp(10005, 0);
    for (int i = 1;i <= n;i ++) cin >> p[i], mp[p[i]] ++;
    LL ans = 0;
    for (int i = 1;i <= n;i ++) {
        for (int v : use) {
            LL x = v ^ p[i];
            if (x > 10000) continue;
            if (x == p[i]) {
                ans += mp[x] - 1;
            } else {
                ans += mp[x];
            }
        }
        mp[p[i]] --;
    }
    cout << ans << '\n';
}

int main() {
    // cout << (1LL << 14) << '\n';
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}