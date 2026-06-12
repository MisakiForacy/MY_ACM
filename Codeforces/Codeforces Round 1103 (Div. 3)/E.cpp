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
    vector<int> a(n + 1, -1);
    vector<vector<int>> dp(n + 1, vector<int> (n + 1, 1));
    for (int i = 1;i <= n;i ++) cin >> a[i];
    for (int l = 1;l <= n;l ++) {
        vector<int> p(n + 1, 0);
        int d = 0;
        for (int r = l;r <= n;r ++) {
            if (p[a[r]] ++ == 0) d ++;
            dp[l][r] = d;
        }
    }
    SegTree f(n);
    auto check = [&](int x) -> int {
        int ok = 0;
        for (int i = x;i <= n;i ++) {
            int l = i - x + 1, r = i;
            int mi = f.qryMi(1, l, r), mx = f.qryMx(1, l, r);
            if (mx - mi + 1 != dp[l][r]) continue;
            for (int j = x;j <= n;j ++) {
                int ll = j - x + 1, rr = j;
                if ((rr >= l && ll <= l) || (ll <= r && r <= rr)) continue;
                int mii = f.qryMi(1, ll, rr), mxx = f.qryMx(1, ll, rr);
                if (!(mii == mx + 1 || mxx == mi - 1)) continue;
                if (mxx - mii + 1 != dp[ll][rr]) continue;
                ok = 1;
            }
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