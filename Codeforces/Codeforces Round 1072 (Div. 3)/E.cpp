#include <bits/stdc++.h>

#define x first
#define y second

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())
#define lowbit(x) ((x) & (-x))

using namespace std;
using LL = long long;

void solve() {
    int n;
    cin >> n;
    vector<LL> a(n + 1, 0), d(n + 1, 0), f(n + 1, 0), Sz(n + 1, 1), Ans(n + 1, 0);
    for (int i = 1;i <= n;i ++) f[i] = i;
    for (int i = 1;i <= n;i ++) cin >> a[i];
    for (int i = 2;i <= n;i ++) d[i] = abs(a[i] - a[i - 1]);
    map<int, vector<int>> Mp;
    for (int i = 2;i <= n;i ++) Mp[d[i]].push_back(i);
    auto findx = [&](auto findx, int x) -> int {
        if (f[x] != x) {
            f[x] = findx(findx, f[x]);
        }
        return f[x];
    };
    auto merge = [&](int u, int v) -> void {
        u = findx(findx, u), v = findx(findx, v);
        if (u == v) return;
        if (u < v) swap(u, v);
        f[u] = v, Sz[v] += Sz[u];
    };
    auto cal = [&](LL v) -> LL {
        return v * (v + 1) / 2;
    };
    for (int i = n - 1;i >= 1;i --) {
        Ans[i] = Ans[i + 1];
        for (int x : Mp[i]) {
            Ans[i] -= cal(Sz[findx(findx, x)]);
            Ans[i] -= cal(Sz[findx(findx, x - 1)]);
            merge(x - 1, x);
            Ans[i] += cal(Sz[findx(findx, x)]);
        }
    }
    for (int i = 1;i < n;i ++) cout << Ans[i] << ' ';
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}