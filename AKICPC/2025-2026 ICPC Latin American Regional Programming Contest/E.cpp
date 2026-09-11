#include <bits/stdc++.h>

#define x first 

#define y second 

#define siz(x) ((int)x.size())

#define all(x) begin(x),end(x)

#define lowbit(x) ((x) & (-x))

using namespace std;

using LL = long long;

const LL inf = 1e15;

struct SegTree
{
    #define lc p << 1
    #define rc p << 1 | 1
    struct node
    {
        LL l, r, cnt, val, laz1, laz2;
    };
    vector<LL> a; vector<node> f;
    SegTree(int _n) {
        a.resize(_n + 1);
        f.resize(_n << 2 | 3);
    }
    void pushup(int p) {
        f[p].cnt = f[lc].cnt + f[rc].cnt;
        f[p].val = min(f[lc].val, f[rc].val);
    }
    void pushdown(int p) {
        if (f[p].laz1) {
            f[lc].cnt += f[p].laz1 * (f[lc].r - f[lc].l + 1);
            f[rc].cnt += f[p].laz1 * (f[rc].r - f[rc].l + 1);
            f[lc].laz1 + f[p].laz1;
            f[rc].laz1 + f[p].laz1;
            f[p].laz1 = 0;
        }
        if (f[p].laz2) {
            f[lc].val += f[p].laz2 * (f[lc].r - f[lc].l + 1);
            f[rc].val += f[p].laz2 * (f[rc].r - f[rc].l + 1);
            f[lc].laz2 + f[p].laz2;
            f[rc].laz2 + f[p].laz2;
            f[p].laz2 = 0;
        }
    }
    void build(int p, int l, int r) {
        f[p].l = l, f[p].r = r;
        if (l == r) {
            f[l].cnt = f[l].val = 0;
            return;
        }
        int mid = l + r >> 1;
        build(lc, l, mid);
        build(rc, mid + 1, r);
        pushup(p);
    }
    void upd1(int p, int l, int r, int v) {
        if (r < l) return;
        if (f[p].l >= l && f[p].r <= r) {
            f[p].cnt += (f[p].r - f[p].l + 1) * v;
            f[p].laz1 += v;
            return;
        }
        int mid = f[p].l + f[p].r >> 1;
        pushdown(p);
        if (l <= mid) upd1(lc, l, r, v);
        if (r >  mid) upd1(rc, l, r, v);
        pushup(p);
    }
    void upd2(int p, int l, int r, int v) {
        if (r < l) return;
        if (f[p].l >= l && f[p].r <= r) {
            f[p].cnt += (f[p].r - f[p].l + 1) * v;
            f[p].laz2 += v;
            return;
        }
        int mid = f[p].l + f[p].r >> 1;
        pushdown(p);
        if (l <= mid) upd2(lc, l, r, v);
        if (r >  mid) upd2(rc, l, r, v);
        pushup(p);
    }
    LL qry1(int p, int l, int r) {
        if (l <= f[p].l && f[p].r <= r) return f[p].cnt;
        int mid = f[p].l + f[p].r >> 1;
        LL cnt = 0;
        pushdown(p);
        if (l <= mid) cnt += qry2(lc, l, r);
        if (r >  mid) cnt += qry2(rc, l, r);
        return cnt;
    }
    LL qry2(int p, int l, int r) {
        if (l <= f[p].l && f[p].r <= r) return f[p].val;
        int mid = f[p].l + f[p].r >> 1;
        LL mi = inf;
        pushdown(p);
        if (l <= mid) mi = min(mi, qry2(lc, l, r));
        if (r >  mid) mi = min(mi, qry2(rc, l, r));
        return mi;
    }
};


void solve() {
    int n;
    cin >> n;
    vector<LL> p(n + 1), use(n + 1), alls;
    vector<char> op(n + 1);
    map<LL, LL> val;
    for (int i = 1;i <= n;i ++) {
        cin >> op[i] >> p[i];
        alls.push_back(p[i]);
    }
    sort(all(alls));
    alls.erase(unique(all(alls)), alls.end());
    for (int i = 1;i <= n;i ++) {
        use[i] = lower_bound(all(alls), p[i]) - alls.begin() + 1;
        val[use[i]] = p[i];
    }
    SegTree f(n);
    f.build(1, 1, n);
    // cout << "ok\n";
    // auto upd = [&](int x, int v) -> void {
    //     for (;x <= n;x += lowbit(x)) f[x] += v;
    // };
    // auto ask = [&](int x) -> LL {
    //     LL res = 0;
    //     for (;x;x -= lowbit(x)) res += f[x];
    //     return res;
    // };
    auto getKth = [&](int k) -> LL {
        if (k == 0) return 0;
        int l = 1, r = n;
        while (l < r) {
            int mid = l + r >> 1;
            if (f.qry1(1, 1, mid) >= k)
                r = mid;
            else
                l = mid + 1;
        }
        return val[l];
    };
    for (int i = 1;i <= n;i ++) {
        if (op[i] == '+') {
            f.upd1(1, use[i], use[i], 1);
            f.upd2(1, 1, use[i] - 1, 1);
        } else {

        }
    }
}

int main() {
    // ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}