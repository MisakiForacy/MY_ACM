#include <bits/stdc++.h>

#define x first
#define y second

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())
#define lowbit(x) ((x) & (-x))

using namespace std;
using LL = long long;
using PII = pair<LL, LL>;

void solve() {
    LL n, m, k;
    cin >> n >> m >> k;
    vector<LL> a(m + 1, 0);
    vector<PII> p(n + 1);
    for (int i = 1;i <= m;i ++) cin >> a[i];
    sort(a.begin() + 1, a.end());
    for (int i = 1;i <= n;i ++) {
        LL x, y, z;
        cin >> x >> y >> z;
        z -= y, k -= y;    
        p[i] = {x, z};
    }
    sort(p.begin() + 1, p.end(), [&](PII x, PII y) {
        if (x.y != y.y) return x.y < y.y;
        return x.x < y.x;
    });
    
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}