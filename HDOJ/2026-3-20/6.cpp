#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

#define x first 
#define y second 

using namespace std;
using LL = long long;
using PLL = pair<LL, LL>;

struct node
{
    LL s, d;
    bool operator < (const node&T) const {
        if (s != T.s) return s < T.s;
        return d > T.d;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<node> p(n);
    for (int i = 0;i < n;i ++) cin >> p[i].s >> p[i].d;
    sort(all(p));
    LL ans = 0, t = 0;
    for (int i = 0;i < n;i ++) {
        if (t < p[i].s) {
            t = p[i].s;
            ans = p[i].s;
        }
        if (t >= p[i].s) {
            t += p[i].d;
            ans += p[i].d;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}