#include <bits/stdc++.h>
#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

#define x first 
#define y second 

#define LOG 20

using namespace std;
using LL = long long;

const LL inf = 1e15;
const int N = 2e5 + 10;

struct Segtree
{   
    #define lc p << 1
    #define rc p << 1 | 1
    struct node {
        LL l, r, Sum;
        node (int x_) : l(x_), r(x_), Sum(x_);
    };
    vector <node> f; vector <LL> a;
    Segtree (int n_) {
        f.resize (n_ << 2 | 3);
        a.resize (n_ + 1);
    }

    void pushup (int p) {
        f[p].Sum = f[lc].Sum + f[rc].Sum;
    }

    void build (int p, int l, int r) {
        f[p].l = l, f[p].r = r;
        if (l == r) {
            f[p].Sum = a[l];
            return;
        }
        int mid = l + r >> 1;
        build (lc, l, mid);
        build (rc, mid + 1, r);
        pushup (p);
    }

    void upd (int p, int x, int val) {
        if (f[p].l == f[p].r) {
            f[p].Sum = val;
            return;
        }
        int mid = f[p].l + f[p].r >> 1;
        if (x <= mid) upd (lc, x, val);
        else          upd (rc, x, val);
        pushup (p);
    }

    LL qry (int p, int l, int r) {
        if (l <= f[p].l && f[p].r <= r) return f[p].Sum;
        LL Sum = 0;
        int mid = f[p].l + f[p].r >> 1;
        if (l <= mid) Sum += qry (lc, l, r);
        if (r >  mid) Sum += qry (rc, l, r);
        return Sum;
    }
}

void solve () {
    int n, q;
    cin >> n >> q;
    deque <int> deq;
    vector <int> p = {0};
    for (int i = 1;i <= n;i ++) {
        int x; cin >> x;
        deq.push_back (x);
    }
    while (siz(deq) > 1) {
        int x = deq.front (); deq.pop_front ();
        int y = deq.front (); deq.pop_front ();
        p.push_back (max(x, y));
        deq.push_back (min(x, y));
    }
    Segtree f(n);
    for (int i = 1;i <= n - 1;i ++) f.a[i] = p[i];
    f.build (1, 1, n);

}

/*

*/

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve ();
}