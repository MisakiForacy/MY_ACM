#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

#define x first 
#define y second 

using namespace std;
using LL = long long;

const LL inf = 1e15;

struct SegTree
{
    #define lc p << 1
    #define rc p << 1 | 1
    struct node
    {
        LL l, r, Mi, Mx;
    };
    vector<node> f; vector<LL> a;
    SegTree(int _n) { f.resize(_n << 2 | 3), a.resize(_n << 1 | 1); }
    void pushup(int p) {
        f[p].Mi = min(f[lc].Mi, f[rc].Mi);
        f[p].Mx = max(f[lc].Mx, f[rc].Mx);
    }
    void build(int p, int l, int r) {
        f[p].l = l, f[p].r = r;
        if (l == r) {
            f[p].Mi = f[p].Mx = a[l];
            return;
        }
        int mid = l + r >> 1;
        build(lc, l, mid);
        build(rc, mid + 1, r);
        pushup(p);
    }
    LL askMi(int p, int l, int r) {
        if (l <= f[p].l && f[p].r <= r) return f[p].Mi;
        LL Mi = inf;
        int mid = f[p].l + f[p].r >> 1;
        if (l <= mid) Mi = min(Mi, askMi(lc, l, r));
        if (r  > mid) Mi = min(Mi, askMi(rc, l, r));
        return Mi;
    }
    LL askMx(int p, int l, int r) {
        if (l <= f[p].l && f[p].r <= r) return f[p].Mx;
        LL Mx = 0;
        int mid = f[p].l + f[p].r >> 1;
        if (l <= mid) Mx = max(Mx, askMx(lc, l, r));
        if (r  > mid) Mx = max(Mx, askMx(rc, l, r));
        return Mx;    
    }
};

void solve() {
    int n;
    cin >> n;
    SegTree f(n);  
    for (int i = 1;i <= n;i ++) cin >> f.a[i];
    f.build(1, 1, n);
    LL ans = 0;
    for (int l = 1;l <= n;l ++) {
        int r = l;
        for (int j = 20;j >= 0;j --) {
            int Tp = r + (1LL << j);
            if (Tp > n) continue;
            if (f.askMx(1, l, Tp) - f.askMi(1, l, Tp) > 1) continue;
            r = Tp;
        }
        ans += r - l + 1;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}