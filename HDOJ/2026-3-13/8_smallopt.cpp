#include <bits/stdc++.h>

// #define x first 
// #define y second 

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;

class IO {
private:
    static const int S = 1 << 20;
    int i = 0, n = 0, o = 0;
    char ib[S], ob[S];

public:
    ~IO() { flush(); }
    inline char gc() {
        if (i >= n) {
            n = (int)fread(ib, 1, S, stdin);
            i = 0;
            if (!n) return 0;
        }
        return ib[i++];
    }
    inline bool skipBlank(char &c) {
        c = gc();
        if (!c) return false;
        while (c <= ' ') {
            c = gc();
            if (!c) return false;
        }
        return true;
    }
    template <class T, typename std::enable_if<std::is_integral<T>::value && std::is_signed<T>::value, int>::type = 0>
    inline bool readInt(T &x) {
        char c;
        if (!skipBlank(c)) return false;
        bool neg = false;
        if (c == '-') {
            neg = true;
            c = gc();
        }
        x = 0;
        while (c >= '0' && c <= '9') {
            x = (T)(x * 10 + (c - '0'));
            c = gc();
        }
        if (neg) x = -x;
        return true;
    }
    template <class T, typename std::enable_if<std::is_integral<T>::value && std::is_unsigned<T>::value, int>::type = 0>
    inline bool readInt(T &x) {
        char c;
        if (!skipBlank(c)) return false;
        x = 0;
        while (c >= '0' && c <= '9') {
            x = (T)(x * 10 + (c - '0'));
            c = gc();
        }
        return true;
    }
    inline bool readFloat(long double &x) {
        std::string s; if (!readString(s)) return false;
        x = strtold(s.c_str(), nullptr); return true;
    }
    inline bool readString(std::string &s) {
        char c;
        if (!skipBlank(c)) return false;
        s.clear();
        while (c > ' ') { s.push_back(c); c = gc(); if (!c) break; }
        return true;
    }
    inline void pc(char c) { if (o == S) flush(); ob[o++] = c; }
    inline void flush() { if (o) fwrite(ob, 1, o, stdout), o = 0; }
    template <class T, typename std::enable_if<std::is_integral<T>::value && std::is_signed<T>::value, int>::type = 0>
    inline IO &writeInt(T x) {
        if (x == 0) return pc('0'), *this;
        if (x < 0) pc('-'), x = -x;
        char s[32];
        int t = 0;
        while (x) s[t++] = (char)('0' + (x % 10)), x /= 10;
        while (t--) pc(s[t]);
        return *this;
    }
    template <class T, typename std::enable_if<std::is_integral<T>::value && std::is_unsigned<T>::value, int>::type = 0>
    inline IO &writeInt(T x) {
        if (x == 0) return pc('0'), *this;
        char s[32];
        int t = 0;
        while (x) s[t++] = (char)('0' + (x % 10)), x /= 10;
        while (t--) pc(s[t]);
        return *this;
    }
    inline IO &writeFloat(long double x) {
        char s[64]; int len = snprintf(s, sizeof(s), "%.12Lg", x);
        for (int k = 0; k < len; ++k) pc(s[k]);
        return *this;
    }
    template <class T, typename std::enable_if<std::is_integral<T>::value, int>::type = 0>
    inline IO &operator>>(T &x) { readInt(x); return *this; }
    inline IO &operator>>(std::string &s) { readString(s); return *this; }
    inline IO &operator>>(char &c) { return skipBlank(c), *this; }
    inline IO &operator>>(bool &b) { int t; readInt(t); b = (t != 0); return *this; }
    inline IO &operator>>(float &x) { long double t; readFloat(t); x = (float)t; return *this; }
    inline IO &operator>>(double &x) { long double t; readFloat(t); x = (double)t; return *this; }
    inline IO &operator>>(long double &x) { readFloat(x); return *this; }
    template <class T, typename std::enable_if<std::is_integral<T>::value, int>::type = 0>
    inline IO &operator<<(T x) { return writeInt(x); }
    inline IO &operator<<(const std::string &s) { for (char c : s) pc(c); return *this; }
    inline IO &operator<<(const char *s) { while (*s) pc(*s++); return *this; }
    inline IO &operator<<(char c) { pc(c); return *this; }
    inline IO &operator<<(bool b) { return *this << (b ? 1 : 0); }
    inline IO &operator<<(float x) { return writeFloat(x); }
    inline IO &operator<<(double x) { return writeFloat(x); }
    inline IO &operator<<(long double x) { return writeFloat(x); }
    template <class A, class B>
    inline IO &operator>>(std::pair<A, B> &p) { *this >> p.first >> p.second; return *this; }
    template <class A, class B>
    inline IO &operator<<(const std::pair<A, B> &p) { *this << p.first << ' ' << p.second; return *this; }
};
inline IO io;
#define cin io
#define cout io

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
    // ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // In.readInt(T);
    cin >> T;
    while (T --) solve();
}