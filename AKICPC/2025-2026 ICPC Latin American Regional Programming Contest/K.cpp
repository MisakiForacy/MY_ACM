#include <bits/stdc++.h>

#define x first 

#define y second 

#define siz(x) ((int)x.size())

#define all(x) begin(x),end(x)

#define lowbit(x) ((x) & (-x))

using namespace std;

using LL = long long;

const LL inf = 1e15;

void solve() {
    LL n, k;
    cin >> n >> k;
    LL l, r, u, d;
    l = inf, r = - inf, u = inf, d = - inf;
    vector<LL> x(n + 1), y(n + 1);
    map<LL, LL> pmi, pmx, qmi, qmx;
    for (int i = 1;i <= n;i ++) {
        cin >> x[i] >> y[i];
        if (pmi.count(x[i] + y[i])) 
            pmi[x[i] + y[i]] = min(pmi[x[i] + y[i]], x[i]);
        else 
            pmi[x[i] + y[i]] = x[i];
        if (pmx.count(x[i] + y[i])) 
            pmx[x[i] + y[i]] = max(pmx[x[i] + y[i]], x[i]);
        else 
            pmx[x[i] + y[i]] = x[i];
        if (qmi.count(x[i] - y[i])) 
            qmi[x[i] - y[i]] = min(qmi[x[i] - y[i]], x[i]);
        else 
            qmi[x[i] - y[i]] = x[i];
        if (qmx.count(x[i] - y[i])) 
            qmx[x[i] - y[i]] = max(qmx[x[i] - y[i]], x[i]);
        else 
            qmx[x[i] - y[i]] = x[i];
        l = min(l, x[i]);
        r = max(r, x[i]);
        u = min(u, y[i]);
        d = max(d, y[i]);
    }
    LL ans = 0;
    for (int i = 1;i <= n;i ++) {
        // 左上，d，r不变
        {
            LL nu, nl;
            nu = min(y[i] - k, u);
            nl = min(x[i] - k, l);
            ans = max(ans, (d - nu + 1) * (r - nl + 1));
        }
        // 右下，u，l不变
        {
            LL nd, nr;
            nd = max(y[i] + k, d);
            nr = max(x[i] + k, r);
            ans = max(ans, (nd - u + 1) * (nr - l + 1));
        }
        // 左下，u，r不变
        {
            LL nd, nl;
            nd = max(y[i] + k, d);
            nl = min(x[i] - k, l);
            ans = max(ans, (nd - u + 1) * (r - nl + 1));
        }
        // 右上，d，l不变
        {
            LL nu, nr;
            nu = min(y[i] - k, u);
            nr = max(x[i] + k, r);
            ans = max(ans, (d - nu + 1) * (nr - l + 1));
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}