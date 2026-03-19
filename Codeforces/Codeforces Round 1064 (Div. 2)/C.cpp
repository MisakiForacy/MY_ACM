#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;

const LL inf = 1e15 + 10;

void solve () {
    int n;
    cin >> n;
    vector <LL> a(n + 1), f(n + 1, 0), pos(n + 1), V(n + 1);
    for (int i = 1;i <= n;i ++) cin >> a[i], V[i] = a[i], pos[i] = i;
    auto find = [&](auto find, int x) -> int {
        if (f[x] != x) {
            V[x] = max(V[x], V[f[x]]);
            f[x] = find(find, f[x]);
        }
        return f[x];
    };
    auto merge = [&](int u, int v) -> void {
        u = find(find, u);
        v = find(find, v);
        if (u == v) return;
        if (V[u] > V[v]) swap (u, v);
        V[v] = max(V[v], V[u]);
        f[u] = v;
    };
    auto cal = [&](int x) -> int {
        return x % n ? x % n : n;
    };
    for (int i = 1;i <= n;i ++) f[i] = i;
    sort (pos.begin() + 1, pos.end(), [&](int x, int y) {
        return a[x] < a[y];
    });
    LL Ans = 0;
    for (int i = 1;i < n;i ++) {
        int cur = pos[i];
        int L = find(find, cal(pos[i] - 1));
        int R = find(find, cal(pos[i] + 1));
        cout << L << ' ' << cur << ' ' << R << '\n';
        LL Add = min(max(V[cur], V[L]), max(V[cur], V[R]));
        Ans += Add;
        if (max(V[cur], V[L]) < max(V[cur], V[R])) merge(cur, L);
        else                                       merge(cur, R);
    }
    cout << Ans << '\n';
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve ();
}