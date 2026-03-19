#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

#define x first 
#define y second 

using namespace std;
using LL = long long;
using PLL = pair<LL, LL>;

const LL inf = 1e15;
const LL MOD = 1e9 + 7;

void solve() {
    LL n, m, l;
    cin >> n >> m >> l;
    vector<LL> x(n + 1, 0), y(m + 1, 0), p(n + 2, inf);
    p[0] = 0;
    for (int i = 1;i <= n;i ++) cin >> x[i], p[i] = p[i - 1] + x[i];
    for (int i = 1;i <= m;i ++) cin >> y[i];
    LL px = 0, L = 1, R = 1;
    while (L <= n && p[L] <= px) L++;
    while (R <= n && p[R] < px + l) R++;
    if (L < R) {
        cout << "YES\n";
        return;
    }
    for (int i = 1; i <= m;i ++) {
        px += y[i];
        while (L <= n && p[L] <= px) L ++;
        while (R <= n && p[R] < px + l) R ++;
        if (L < R) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}