#include <bits/stdc++.h>

#define double long double

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

#define x first 
#define y second 

using namespace std;
using LL = long long;
using PLL = pair<LL, LL>;

const LL inf = 1e15;
const LL MOD = 1e9 + 7;

struct node 
{
    LL x, y, w;
    bool operator < (const node&T) const {
        return w > T.w;
    }
};

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

map<PLL, int> id;

int cnt = 0;

struct SegTree 
{
    #define lc p << 1
    #define rc p << 1 | 1
    struct node
    {
        int l, r, S, bad, id;
        node() { bad = 0; }
    };
    vector<node> f; vector<LL> a;
    SegTree(int _n) { f.resize(_n << 2 | 3), a.resize(_n + 1); }
    void pushup(int p) {
        f[p].S = f[lc].S + f[rc].S;
    }
    void build(int p, int l, int r) {
        f[p].l = l, f[p].r = r;
        id[{l, r}] = p;
        if (l == r) {
            f[p].S = a[l];
            return;
        }
        int mid = l + r >> 1;
        build(lc, l, mid);
        build(rc, mid + 1, r);
        pushup(p);
    }
    LL qry(int p, int l, int r) {
        if (!f[p].bad) cnt ++;
        if (l <= f[p].l && f[p].r <= r && !f[p].bad) return f[p].S;
        int mid = f[p].l + f[p].r >> 1;
        int S = 0;
        if (l <= mid) S += qry(lc, l, r);
        if (r  > mid) S += qry(rc, l, r);
        return S;
    }
};

void solve() {
    int q;
    cin >> q;
    SegTree f(q);
    for (int i = 1;i <= q;i ++) f.a[i] = 1;
    f.build(1, 1, q);
    while (q --) {
        int opt, l, r;
        cin >> opt >> l >> r;
        if (opt == 1) {
            f.f[id[{l, r}]].bad = 1;
        } else {
            cnt = 0;
            f.qry(1, l, r);
            cout << cnt << '\n';
        }
    }
}

int main() {
    cout << fixed << setprecision(10);
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}