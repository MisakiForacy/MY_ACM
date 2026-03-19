#include <bits/stdc++.h>
#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

#define x first 
#define y second 

using namespace std;
using LL = long long;

struct SegTree
{  
    #define lc p << 1
    #define rc p << 1 | 1
    struct node
    {
        LL l, r, Mx, Mi;
    };
    vector<node> f; vector<LL> a;
    SegTree (int _n) {
        f.resize(_n << 2 | 1), a.resize (_n + 1);
    }
    void pushup(int p) {
        f[p].Mx = max(f[lc].Mx, f[rc].Mx);
        f[p].Mi = min(f[lc].Mi, f[rc].Mi);
    }
    void build (int p, int l, int r) {
        f[p].l = l, f[p].r = r;
        if (l == r) {
            f[p].Mx = a[l];
            f[p].Mi = a[l];
            return;
        }
        int mid = l + r >> 1;
        build (lc, l, mid);
        build (rc, mid + 1, r);
        pushup(p);
    }
    LL qry (int p, int l, int r) {
        if (l <= f[p].l && f[p].r <= r) return f[p].Mx;
        int mid = f[p].l + f[p].r >> 1;
        LL Max = -1e18;
        if (l <= mid) Max = max(Max, qry (lc, l, r));
        if (r >  mid) Max = max(Max, qry (rc, l, r));
        return Max;
    }
    LL qryMi (int p, int l, int r) {
        if (l <= f[p].l && f[p].r <= r) return f[p].Mi;
        int mid = f[p].l + f[p].r >> 1;
        LL Min = 1e18;
        if (l <= mid) Min = min(Min, qryMi (lc, l, r));
        if (r >  mid) Min = min(Min, qryMi (rc, l, r));
        return Min;
    }
};

void solve () {
    LL n, k;
    cin >> n >> k;
    vector<LL> a(n + 1, 0), p(n + 1, 0), b(n + 1, 0);
    for (int i = 1;i <= n;i ++) cin >> a[i], p[i] = p[i - 1] + a[i];
    for (int i = 1;i <= n;i ++) cin >> b[i];
    SegTree f(n);
    for (int i = 1;i <= n;i ++) f.a[i] = p[i];
    f.build(1, 1, n);
    LL Max = -1e18;
    if (k == 1) {
        for (int i = 1;i <= n;i ++) {
            LL Val = 0;
            Val += a[i] + b[i];
            Val += max(0LL, p[i - 1] - min(0LL, f.qryMi(1, 1, i - 1)));
            Val += max(0LL, f.qry(1, i + 1, n) - p[i]);
            Max = max(Max, Val);
        }
        cout << Max << '\n';
    } else if (k & 1) {
        stack<int> stk;
        vector<int> L(n + 2, 0), R(n + 2, 0);
        for (int i = n;i >= 1;i --) {
            while (siz(stk) && b[stk.top()] <= b[i]) stk.pop();
            R[i] = siz(stk) ? stk.top() : n + 1;
            stk.push(i);
        } 
        while (siz(stk)) stk.pop();
        for (int i = 1;i <= n;i ++) {
            while (siz(stk) && b[stk.top()] <= b[i]) stk.pop();
            L[i] = siz(stk) ? stk.top() : 0;
            stk.push(i);
        }
        for (int i = 1;i <= n;i ++) {
            LL Val = 0;
            Val += a[i] + b[i];
            if (L[i] <= i - 1) {
                if (L[i] == 0) {
                    Val += max(0LL, p[i - 1] - min(0LL, f.qryMi(1, L[i] + 1, i - 1)));
                } else {
                    Val += max(0LL, p[i - 1] - f.qryMi(1, L[i] + 1, i - 1));
                }
            }
            if (i + 1 <= R[i]) 
                Val += max(0LL, f.qry(1, i + 1, R[i] - 1) - p[i]);

            Max = max(Max, Val);
        }
        cout << Max << '\n';
    } else {
        LL Mi = 0;
        for (int i = 1;i <= n;i ++) {
            Max = max(Max, p[i] - Mi);
            Mi = min(Mi, p[i]);
        }
        cout << Max << '\n';
    }
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve ();
}