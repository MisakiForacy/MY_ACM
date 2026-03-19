#include <bits/stdc++.h>
#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

#define x first 
#define y second 

using namespace std;
using LL = long long;

const LL MOD = 1e9 + 7;

struct SegTree
{
    #define lc p << 1
    #define rc p << 1 | 1
    struct node
    {
        LL l, r, Cnt, SumL, SumR;
        node () {l = r = Cnt = SumL = SumR = 0;}
    };
    int n;
    vector<LL> S, L, R;
    vector<node> f;
    SegTree (int _n) {
        n = _n;
        S.resize (_n + 1, 0);
        L.resize (_n + 1, 0);
        R.resize (_n + 1, 0);
        f.resize (_n + 1 << 2);
    } 

    void pushup (int p) {
        f[p].Cnt = f[lc].Cnt + f[rc].Cnt;
        f[p].SumL = f[lc].SumL + f[rc].SumL;
        f[p].SumR = f[lc].SumR + f[rc].SumR;
    } 

    void build (int p, int l, int r) {
        f[p].l = l, f[p].r = r;
        if (l == r) {
            f[p].Cnt  = S[l];
            f[p].SumL = L[l];
            f[p].SumR = R[l];
            return;
        }
        int mid = l + r >> 1;
        build (lc, l, mid);
        build (rc, mid + 1, r);
        pushup (p);
    } 

    void upd (int p, int idx, int opt) {
        if (f[p].l == f[p].r) {
            if (opt == 2) {
                f[p].Cnt = 0;
                f[p].SumL = 0;
                f[p].SumR = 0;
            } else if (opt == 1) {
                f[p].Cnt = 1;
                f[p].SumL = idx;
                f[p].SumR = n - idx + 1;
            }
            return;
        }
        int mid = f[p].l + f[p].r >> 1;
        if (idx <= mid) upd (lc, idx, opt);
        else            upd (rc, idx, opt);
        pushup (p);
    } 

    LL qryCnt (int p, int l, int r) {
        if (l > r) return 0;
        if (l <= f[p].l && f[p].r <= r) return f[p].Cnt;
        LL Cnt = 0;
        LL mid = f[p].l + f[p].r >> 1;
        if (l <= mid) Cnt += qryCnt (lc, l, r);
        if (r >  mid) Cnt += qryCnt (rc, l, r);
        return Cnt;
    } 

    LL qrySumL (int p, int l, int r) {
        if (l > r) return 0;
        if (l <= f[p].l && f[p].r <= r) return f[p].SumL;
        LL Sum = 0;
        LL mid = f[p].l + f[p].r >> 1;
        if (l <= mid) Sum += qrySumL (lc, l, r);
        if (r >  mid) Sum += qrySumL (rc, l, r);
        return Sum;
    } 

    LL qrySumR (int p, int l, int r) {
        if (l > r) return 0;
        if (l <= f[p].l && f[p].r <= r) return f[p].SumR;
        LL Sum = 0;
        LL mid = f[p].l + f[p].r >> 1;
        if (l <= mid) Sum += qrySumR (lc, l, r);
        if (r >  mid) Sum += qrySumR (rc, l, r);
        return Sum;
    } 

};

void solve () {
    int n, m;
    cin >> n;
    string s;
    cin >> s;
    s = ' ' + s;
    SegTree f(n);
    for (int i = 1;i <= n;i ++) f.S[i] = (s[i] == '1');
    for (int i = 1;i <= n;i ++) f.L[i] = i * (s[i] == '1');
    for (int i = 1;i <= n;i ++) f.R[i] = (n - i + 1) * (s[i] == '1');
    f.build(1, 1, n);
    LL Cnt = 0;
    for (int i = 1;i <= n;i ++) {
        if (s[i] == '1') {
            Cnt += f.qryCnt (1, 1, i - 1) * i - f.qrySumL (1, 1, i - 1);
        }
    }

    cout << Cnt % MOD << '\n';
    cin >> m;
    for (int i = 1;i <= m;i ++) {
        int opt, idx;
        cin >> opt >> idx;
        if (opt == 2) {
            Cnt -= f.qryCnt (1, 1, idx - 1) * idx - f.qrySumL (1, 1, idx - 1);
            Cnt -= f.qryCnt (1, idx + 1, n) * (n - idx + 1) - f.qrySumR (1, idx + 1, n);
            cout << Cnt % MOD << '\n';
        } else if (opt == 1) {
            Cnt += f.qryCnt (1, 1, idx - 1) * idx - f.qrySumL (1, 1, idx - 1);
            Cnt += f.qryCnt (1, idx + 1, n) * (n - idx + 1) - f.qrySumR (1, idx + 1, n);
            cout << Cnt % MOD << '\n';
        }
        f.upd (1, idx, opt);
    }
}

int main () {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}