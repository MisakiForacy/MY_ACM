#include <bits/stdc++.h>
using namespace std;

using LL = long long;

struct Occ {
    int pos;
    int tp;
};

void solve() {
    int n;
    cin >> n;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];

    vector<vector<Occ>> occ(n + 2);

    for (int i = 1; i <= n; ++i) {
        int b;
        cin >> b;
        if (a[i] == b) {
            occ[a[i]].push_back({i, 2});
        } else {
            occ[a[i]].push_back({i, 0});
            occ[b].push_back({i, 1});
        }
    }

    vector<int> endPos(n + 1, n);

    for (int v = n; v >= 1; --v) {
        int j = 0;
        auto &cur = occ[v];
        auto &nxt = occ[v + 1];

        for (const auto &e : cur) {
            if (e.tp != 2) continue;
            while (j < (int)nxt.size() && nxt[j].pos <= e.pos) ++j;
            if (j == (int)nxt.size()) {
                endPos[e.pos] = n;
            } else if (nxt[j].tp == 2) {
                endPos[e.pos] = endPos[nxt[j].pos];
            } else {
                endPos[e.pos] = nxt[j].pos - 1;
            }
        }
    }

    LL ans = 0;
    int p = 0;
    auto &ones = occ[1];

    for (int L = 1; L <= n; ++L) {
        while (p < (int)ones.size() && ones[p].pos < L) ++p;

        if (p == (int)ones.size()) {
            ans += n - L + 1;
        } else if (ones[p].tp == 2) {
            ans += endPos[ones[p].pos] - L + 1;
        } else {
            ans += ones[p].pos - L;
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int multTestQ;
    cin >> multTestQ;
    while (multTestQ--) solve();

    return 0;
}