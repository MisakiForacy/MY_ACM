#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    LL n; cin >> n;
    LL Ans = n + n * (n - 1) / 2;
    vector<LL> p(n + 1, 0), pos(n + 1, 0), f(n + 1, 0);
    for (int i = 1;i <= n;i ++) cin >> p[i], pos[p[i]] = i;
    auto upd = [&](int x, int v) -> void {
        for (;x <= n;x += -x & x) f[x] += v;
    };
    auto qry = [&](int x) -> int {
        LL Sm = 0;
        for (;x;x -= -x & x) Sm += f[x];
        return Sm;
    };
    auto qrySum = [&](int l, int r) -> int {
        return qry(r) - qry(l - 1);
    };
    for (int i = 1;i <= n;i ++) upd(i, 1);
    for (int i = n;i >= 1;i --) {
        int idx = pos[i];
        upd(idx, -1);
        LL L = qrySum(1, idx), R = qrySum(idx, n);
        Ans += L * R;
    }
    cout << Ans << '\n';
}