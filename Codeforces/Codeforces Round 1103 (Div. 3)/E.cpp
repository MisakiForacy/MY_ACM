#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

#define lowbit(x) ((x) & (-x))

using namespace std;
using LL = long long;

const LL inf = 1e15;

struct SegTree
{
    struct node
    {
        LL l, r, Mi, Mx;
        node(){Mi = inf, Mx = - inf;}
    };
    vector<node> f; vector<LL> a;
    SegTree(int _n) {f.resize(_n << 2 | 3), a.resize(_n + 1); }
    void pushup(int p) {
        f[p].Mi = min(f[p << 1].Mi, f[p << 1 | 1].Mi);
        f[p].Mx = max(f[p << 1].Mx, f[p << 1 | 1].Mx);
    }
    void build(int p, int l, int r) {
        f[p].l = l, f[p].r = r;
        if (l == r) {
            f[p].Mi = a[l];
            return;
        }
        int Mid = l + r >> 1;
        build(p << 1, l, Mid);
        build(p << 1 | 1, Mid + 1, r);
        pushup(p);
    }
    void upd(int p, int idx, int v) {
        if (f[p].l == f[p].r) {
            f[p].Mi = v;
            return;
        }
        int Mid = f[p].l + f[p].r >> 1;
        if (idx <= Mid) upd(p << 1, idx, v);
        else        upd(p << 1 | 1, idx, v);
        pushup(p);
    }
    LL qryMi(int p, int l, int r) {
        if (l <= f[p].l && f[p].r <= r) return f[p].Mi;
        LL Mi = inf, Mid = f[p].l + f[p].r >> 1;
        if (l <= Mid) Mi = min(Mi, qryMi(p << 1, l, r));
        if (r > Mid) Mi = min(Mi, qryMi(p << 1 | 1, l, r));
        return Mi;
    }
    LL qryMx(int p, int l, int r) {
        if (l <= f[p].l && f[p].r <= r) return f[p].Mx;
        LL Mx = - inf, Mid = f[p].l + f[p].r >> 1;
        if (l <= Mid) Mx = max(Mx, qryMx(p << 1, l, r));
        if (r > Mid) Mx = max(Mx, qryMx(p << 1 | 1, l, r));
        return Mx;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1, -1), dp(n + 1, 1);
    for (int i = 1;i <= n;i ++) cin >> a[i];
    for (int l = 1;l <= n;l ++) {
        
    }
    SegTree t(n);
    vector<int> f1(n + 1, 0), f2(n + 1, 0);
    auto upd1 = [&](int x, int v) -> void {
        for (;x <= n;x += lowbit(x)) f1[x] += v;
    };
    auto qry1 = [&](int x) -> int {
        int sum = 0;
        for (;x;x -= lowbit(x)) sum += f1[x];
        return sum;
    };
    auto upd2 = [&](int x, int v) -> void {
        for (;x <= n;x += lowbit(x)) f2[x] += v;
    };
    auto qry2 = [&](int x) -> int {
        int sum = 0;
        for (;x;x -= lowbit(x)) sum += f2[x];
        return sum;
    };
    auto check = [&](int x) -> int {
        int ok = 0;
        for (int i = 1;i <= x;i ++) upd1(a[i], 1);
        for (int i = x;i <= n - x;i ++) {
            int l = i - x + 1, r = i;
            int mi = t.qryMi(1, l, r), mx = t.qryMx(1, l, r);
            if (mx - mi == qry1(mx) - qry1(mi - 1)) 
        }
        return ok;
    };
    // int lo = 0, hi = n / 2;
    // while (lo < hi) {
    //     int mid = lo + hi >> 1;
    //     if (check(mid)) 
    //         lo = mid + 1;
    //     else 
    //         hi = mid;
    // }
    cout << check(4) << '\n';
    // if (!check(lo)) lo --;
    // cout << lo << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}