#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;

const int N = 5e5;

struct SegTree 
{
    #define lc p << 1
    #define rc p << 1 | 1
    struct node 
    {
        LL l, r, Sum, Cnt;
        node () { l = r = Sum = Cnt = 0;}
    };
    int n;
    vector<node> f; vector<LL> a, v;
    SegTree (int n_) {
        this->n = n_;
        f.resize(n_ << 2 | 1);
        a.resize(n_ + 1);
        v.resize(n_ + 1, 0);
    }
    void pushup (int p) {
        f[p].Sum = f[lc].Sum + f[rc].Sum;
        f[p].Cnt = f[lc].Cnt + f[rc].Cnt;
    }
    void build (int p, int l, int r) {
        f[p].l = l, f[p].r = r;
        if (l == r) {
            f[p].Sum += v[l] * a[l];
            f[p].Cnt += v[l];
            return;
        }
        int mid = l + r >> 1;
        build (lc, l, mid);
        build (rc, mid + 1, r);
        pushup (p);
    }
    void upd (int p, int x, int op) {
        if (f[p].l == f[p].r) {
            f[p].Cnt += op;
            f[p].Sum += x * op;
            return;
        }
        int mid = f[p].l + f[p].r >> 1;
        if (x <= mid) upd (lc, x, op);
        else          upd (rc, x, op);
        pushup (p);
    }
    LL qrySum (int p, int l, int r) {
        if (l <= f[p].l && f[p].r <= r) return f[p].Sum;
        LL Sum = 0;
        int mid = f[p].l + f[p].r >> 1;
        if (l <= mid) Sum += qrySum (lc, l, r);
        if (r  > mid) Sum += qrySum (rc, l, r);
        return Sum;
    }
    LL qryCnt (int p, int l, int r) {
        if (l <= f[p].l && f[p].r <= r) return f[p].Cnt;
        LL Cnt = 0;
        int mid = f[p].l + f[p].r >> 1;
        if (l <= mid) Cnt += qryCnt (lc, l, r);
        if (r  > mid) Cnt += qryCnt (rc, l, r);
        return Cnt;
    }
};

void solve () {
    int n, m;
    cin >> n >> m;
    SegTree f(N);
    vector<LL> a(n + 1, 0);
    LL z = 0;
    for (int i = 0;i <= N;i ++) f.a[i] = i;
    for (int i = 1;i <= n;i ++) {
        cin >> a[i];
        f.v[a[i]] += 1;
        if (a[i] == 0) z ++;
    }
    f.build (1, 1, N);
    for (int i = 1;i <= m;i ++) {
        int opt, x, y;
        cin >> opt >> x >> y;
        if (opt == 1) {
            if (y == 0) z ++;
            if (a[x] == 0) z --;
            if (a[x]) f.upd (1, a[x], -1);
            if (  y ) f.upd (1,   y,   1);
            a[x] = y;
        } else {
            LL ans = 0;
            if (x <= y) {
                ans += f.qryCnt (1, 1, x - 1) * x;
                ans += f.qryCnt (1, y + 1, N) * y;
                ans += f.qrySum (1, x, y);
                ans += z * x;
            } else {
                ans = n * x;
            }
            cout << ans << '\n';
        }
    }
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    solve ();
}