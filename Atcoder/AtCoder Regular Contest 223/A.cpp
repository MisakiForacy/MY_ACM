#include <bits/stdc++.h>

#define all(x) begin(x),end(x)

#define siz(x) ((int)x.size())

using namespace std;

using LL = long long;

struct node
{
    __int128_t w, v;
};

void solve() {
    LL n, w;
    cin >> n >> w;
    vector<node> p(n + 1);
    vector<__int128_t> prev(n + 1, 0), prew(n + 1, 0);
    __int128_t ans = 0;
    for (int i = 1;i <= n;i ++) {
        LL ww, vv;
        cin >> ww >> vv;
        p[i].w = ww;
        p[i].v = vv;
        prew[i] = i ? prew[i - 1] + ww : ww;
        prev[i] = i ? prev[i - 1] + vv : vv;
    }
    auto dfs = [&](auto dfs, LL idx, LL W) -> __int128_t {
        if (idx == 0) return 0;
        if (p[idx].w > W) {
            return dfs(dfs, idx - 1, W);
        } else {
            return max(dfs(dfs, idx - 1, W - p[idx].w) + p[idx].v, prev[idx - 1]);
        }
    };
    ans = dfs(dfs, n, w);
    string s;
    while (ans) {
        s += ans % 10 + '0';
        ans /= 10;
    }
    reverse(all(s));
    cout << s << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}