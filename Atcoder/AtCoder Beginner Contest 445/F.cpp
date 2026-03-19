#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

#define x first 
#define y second 

using namespace std;
using LL = long long;
using PLL = pair<LL, LL>;

const LL inf = 1e18;

struct SegTree
{
    #define lc p << 1
    #define rc p << 1 | 1
    struct node
    {
        LL l, r, S;
    };
    vector<node> f; vector<LL> a;
    SegTree(int _n) { f.resize(_n << 2 | 1), a.resize(_n + 1); }
    void pushup(int p) {
        f[p].S = f[lc].S + f[rc].S;
    }
    void build(int p, int l, int r) {
        f[p].l = l, f[p].r = r;
        if (l == r) {
            f[p].S = a[l];
            return;
        }
        int mid = l + r >> 1;
        build(lc, l, mid);
        build(rc, mid + 1, r);
        pushup(p);
    }
    void upd(int p, int idx, int v) {
        if (f[p].l == f[p].r) return f[p].S;
        int mid = f[p].l + f[p].r >> 1;
        if (idx <= mid) upd(lc, idx, v);
        else            upd(rc, idx, v);
        pushup(p);
    }
    int qry(int p, int l, int r) {
        if (l <= f[p].l && f[p].r <= r) return f[p].S;
        int mid = f[p].l + f[p].r >> 1;
        int sum = 0;
        if (l <= mid) sum += qry(lc, l, r);
        if (r  > mid) sum += qry(rc, l, r);
        return sum;
    }
};

void solve() {

}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}
