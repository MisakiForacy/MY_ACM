#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

#define x first 
#define y second 

#define LOG 40

using namespace std;
using LL = long long;

mt19937_64 rnd(time(0));

const LL inf = 2e9;

struct DynamicSegmentTree
{
    LL n, ncnt = 0, rt = 0;
    vector<LL> rc, lc, Max, Min;
    DynamicSegmentTree (int _n = 0) 
    {
        this->n = _n + 1;
        lc.resize(n * LOG, 0);
        rc.resize(n * LOG, 0);
        Min.resize(n * LOG, inf);
        Max.resize(n * LOG, 0);
    }
    void pushup (int p) {
        Max[p] = max(Max[lc[p]], Max[rc[p]]);
        Min[p] = min(Min[lc[p]], Min[rc[p]]);
    }
    void upd (LL &p, int l, int r, int x, int val) {
        if (!p) { p = ++ ncnt;}
        if (l == r) {
            Min[p] = val;
            Max[p] = val;
            return;
        }
        int mid = l + r >> 1;
        if (x <= mid) upd (lc[p], l, mid, x, val);
        else          upd (rc[p], mid + 1, r, x, val);
        pushup (p);
    }
    LL askMax (int p, int l, int r, int L, int R) {
        if (L > R) return -1;
        if (!p) return 0;
        if (L <= l && r <= R) return Max[p];
        LL Max = 0;
        int mid = l + r >> 1;
        if (L <= mid) Max = max(Max, askMax (lc[p], l, mid, L, R));
        if (R >  mid) Max = max(Max, askMax (rc[p], mid + 1, r, L, R));
        return Max;
    }
};

void solve () {
    int n;
    cin >> n;

    LL X = 1e9 + 1;

    DynamicSegmentTree f(n);

    f.upd(f.rt, 0, X, 0, 0);

    LL ans = 0;

    for (int i = 1;i <= n;i ++) {
        int x;
        cin >> x;
        LL R = f.askMin(f.rt, 0, X, x, X);
        LL L = f.askMax(f.rt, 0, X, 0, x);

        LL RR = f.askMin(f.rt, 0, X, R + 1, X);
        LL LL = f.askMax(f.rt, 0, X, 0, L - 1);

        if (R != inf) {
            ans -= (RR == -1 ? R - L : min(RR - R, R - L));
            ans -= (LL == -1 ? R - L : min(L - LL, R - L));
        } else {
            ans -= (LL == -1 ? 0LL : L - LL);
        }

        f.upd(f.rt, 0, X, x, x);

        if (R != inf) {
            ans += (RR == -1 ? R - x : min(RR - R, R - x));
            ans += (LL == -1 ? x - L : min(L - LL, x - L));
        } else {
            ans += (LL == -1 ? x - L : min(L - LL, x - L));
        }
        if (R != inf)
            ans += min(R - x, x - L);
        else
            ans += x - L;

        cout << ans << '\n';
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