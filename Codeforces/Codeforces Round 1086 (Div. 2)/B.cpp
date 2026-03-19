#include <bits/stdc++.h>

#define x first 
#define y second 

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;
using PLL = pair<LL, LL>;

struct node
{
    LL a, p;
};

void solve() {
    int n, k, p, m;
    cin >> n >> k >> p >> m;
    vector<node> a(n + 2);
    for (int i = 1;i <= n;i ++) cin >> a[i].a, a[i].p = 0;
    a[p].p = 1;
    int ans = 0;
    while (m) {
        int mi = 100000, id = 0;
        for (int i = 1;i <= k;i ++) {
            if (a[i].p) {
                mi = a[i].a;
                id = i;
                break;
            } else if (a[i].a < mi) {
                mi = a[i].a;
                id = i;
            }
        }
        if (mi > m) break;
        if (a[id].p) ans ++;
        m -= mi;
        a[n + 1] = a[id];
        for (int i = id;i <= n;i ++) a[i] = a[i + 1];
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}