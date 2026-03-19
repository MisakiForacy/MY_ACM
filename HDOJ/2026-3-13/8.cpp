#include <bits/stdc++.h>

#define x first 
#define y second 

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;

namespace fio {
struct IO {
    static const int S = 1 << 20;
    int i = 0, n = 0, o = 0; char ib[S], ob[S];
    ~IO() { flush(); }
    inline char gc() {
        if (i >= n) { n = (int)fread(ib, 1, S, stdin); i = 0; if (!n) return 0; }
        return ib[i++];
    }
    template <class T>
    inline bool rd(T &x) {
        char c = gc(); if (!c) return false;
        T s = 1; x = 0;
        while (c != '-' && (c < '0' || c > '9')) {
            c = gc(); if (!c) return false;
        }
        if (c == '-') s = -1, c = gc();
        while (c >= '0' && c <= '9') x = x * 10 + (c - '0'), c = gc();
        x *= s;
        return true;
    }
    inline void pc(char c) { if (o == S) flush(); ob[o++] = c; }
    inline void flush() { if (o) fwrite(ob, 1, o, stdout), o = 0; }

    inline IO &wt(long long x) {
        if (!x) return pc('0'), *this;
        if (x < 0) pc('-'), x = -x;
        char s[24]; int t = 0;
        while (x) s[t++] = (char)('0' + x % 10), x /= 10;
        while (t--) pc(s[t]);
        return *this;
    }
    inline IO &operator>>(int &x) { rd(x); return *this; }
    inline IO &operator>>(long long &x) { rd(x); return *this; }
    inline IO &operator<<(int x) { return wt(x); }
    inline IO &operator<<(long long x) { return wt(x); }
    inline IO &operator<<(char c) { pc(c); return *this; }
    inline IO &operator<<(const char *s) { while (*s) pc(*s++); return *this; }
};
inline IO io; inline IO &cin = io; inline IO &cout = io;
}
#define cin fio::cin
#define cout fio::cout


struct SegTree
{
    #define lc p << 1
    #define rc p << 1 | 1
    struct node
    {
        int l, r, mxa, mxb;
        vector<array<int, 3>> v;
        vector<int> pa, sb, vv;
    };
    vector<node> f; vector<int> v, a, b;
    SegTree(int _n) { 
        f.resize(_n << 2 | 3);
        v.resize(_n + 1);
        a.resize(_n + 1); 
        b.resize(_n + 1);
    }
    void pushup(int p) {
        // for (auto [x, y, z] : f[lc].v) f[p].v.push_back({x, y, z}), f[p].vv.push_back(x);
        // for (auto [x, y, z] : f[rc].v) f[p].v.push_back({x, y, z}), f[p].vv.push_back(x);
        // sort(all(f[p].v), [&](array<int, 3> x, array<int, 3> y) {return x[0] < y[0];});
        // sort(all(f[p].vv));
        int l = 0, r = 0;
        while (l < siz(f[lc].vv) || r < siz(f[rc].vv)) {
            if (l == siz(f[lc].vv)) {
                f[p].vv.push_back(f[rc].vv[r]);
                f[p].v.push_back(f[rc].v[r++]);
            } else if (r == siz(f[rc].vv)) {
                f[p].vv.push_back(f[lc].vv[l]);
                f[p].v.push_back(f[lc].v[l++]);
            } else if (f[lc].vv[l] <= f[rc].vv[r]) {
                f[p].vv.push_back(f[lc].vv[l]);
                f[p].v.push_back(f[lc].v[l++]);
            } else {
                f[p].vv.push_back(f[rc].vv[r]);
                f[p].v.push_back(f[rc].v[r++]);
            }
        }
        int len = f[p].r - f[p].l + 1;
        f[p].pa.resize(len, 0);
        f[p].sb.resize(len, 0);
        f[p].pa[0] = f[p].v[0][1];
        f[p].sb[len - 1] = f[p].v[len - 1][2];
        for (int i = 1;i < len;i ++) {
            f[p].pa[i] = max(f[p].pa[i - 1], f[p].v[i][1]);
        }
        for (int i = len - 2;i >= 0;i --) {
            f[p].sb[i] = max(f[p].sb[i + 1], f[p].v[i][2]);
        }
    }
    void build(int p, int l, int r) {
        f[p].l = l, f[p].r = r;
        if (l == r) {
            f[p].vv.push_back(v[l]);
            f[p].v.push_back({v[l], a[l], b[l]});
            f[p].pa.push_back(a[l]);
            f[p].sb.push_back(b[l]);
            return;
        }
        int mid = l + r >> 1;
        build(lc, l, mid);
        build(rc, mid + 1, r);
        pushup(p);
    }
    LL qry(int p, int l, int r, LL x, LL y) {
        if (l <= f[p].l && f[p].r <= r) {
            LL need = y - x;
            int idx = lower_bound(all(f[p].vv), need) - f[p].vv.begin();
            if (idx > f[p].r - f[p].l) {
                return (LL)f[p].pa[idx - 1] + x;
            } else if (idx == 0) {
                return (LL)f[p].sb[idx] + y;
            } else {
                return max((LL)f[p].pa[idx - 1] + x, (LL)f[p].sb[idx] + y);
            }
        }
        int mid = f[p].l + f[p].r >> 1;
        LL mx = 0;
        if (l <= mid) mx = max(mx, qry(lc, l, r, x, y));
        if (r  > mid) mx = max(mx, qry(rc, l, r, x, y));
        return mx;
    }
};

void solve() {
    int n, q;
    // In.readInt(n);
    // In.readInt(q);
    cin >> n >> q;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1;i <= n;i ++) {
        cin >> a[i] >> b[i];
    }
    SegTree f(n);
    for (int i = 1;i <= n;i ++) f.v[i] = a[i] - b[i], f.a[i] = a[i], f.b[i] = b[i];
    f.build(1, 1, n);
    LL ans = 0;
    while (q --) {
        int l, r;
        LL X, Y;
        cin >> l >> r >> X >> Y;
        LL x = X ^ ans, y = Y ^ ans;
        ans = f.qry(1, l, r, x, y);
        cout << ans << '\n';
    }
}

int main() {
    int T = 1;
    // In.readInt(T);
    cin >> T;
    while (T --) solve();
}