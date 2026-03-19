#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

#define x first 
#define y second 

using namespace std;
using LL = long long;
using PII = pair<LL, LL>;

const LL inf = 1e18 + 10;

struct node
{
    LL a, b, c, d;
};

void solve() {
    LL n, x;
    cin >> n >> x;
    vector<node> p;
    LL ok = 0, Mx = 0, add = 0;
    for (int i = 1;i <= n;i ++) {
        LL a, b, c;
        cin >> a >> b >> c;
        add += (b - 1) * a;
        Mx = max(Mx, a * b - c);
    }
    if (add >= x) {
        cout << 0 << '\n';
    } else {
        if (Mx <= 0) {
            cout << -1 << '\n';
        } else {
            LL use = x - add;
            LL ans = (use + Mx - 1) / Mx;
            cout << ans << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}