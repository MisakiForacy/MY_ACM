#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;
using PLL = pair<LL, LL>;

const LL MOD = 1006903069;

void solve() {
    int n, k1, k2;
    cin >> n;
    cin >> k1;
    map<LL, vector<PLL>> Mpx;
    map<LL, vector<LL>> Mpy;
    map<pair<LL, LL>, LL> vy;
    for (int i = 1;i <= k1;i ++) {
        LL x, y, v;
        cin >> x >> y >> v;
        Mpx[x].push_back({y, v});
    }
    cin >> k2;
    for (int i = 1;i <= k2;i ++) {
        LL x, y, v;
        cin >> x >> y >> v;
        Mpy[y].push_back(x);
        vy[{x, y}] = v;
    }
    for (auto &[x, vec] : Mpy) sort(all(vec));
    LL res = 0;
    for (int i = 1;i <= n;i ++) {
        LL Sm = 0;
        // cout << "cur i : " << i << '\n';
        for (auto vec : Mpx[i]) {
            // cout << vec.first << ' ' << vec.second << '\n';
            int id = lower_bound(all(Mpy[i]), vec.first) - Mpy[i].begin();
            if (id >= Mpy[i].size()) continue;
            if (*lower_bound(all(Mpy[i]), vec.first) == vec.first) {
                // cout << "ok : " << vec.second << ' ' << vy[{vec.first, i}] << '\n';
                Sm += vec.second * vy[{vec.first, i}] % MOD;
                Sm %= MOD;
            }
        }
        // cout << Sm << '\n';
        res += Sm;
        res %= MOD;
    }
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}