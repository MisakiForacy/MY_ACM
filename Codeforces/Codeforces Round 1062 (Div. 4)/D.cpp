#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())
using namespace std;
using LL = long long;

int N = 2e5 + 10;

vector<LL> p, s(N, 0);

const LL inf = 1e18;

void Euler() {
    s[1] = 1;
    for (int i = 2;i < N;i ++) {
        if (!s[i]) p.push_back(i);
        for (int j = 0;j < siz(p) && p[j] * i < N;j ++) {
            s[p[j] * i] = 1;
            if (i % p[j] == 0) break;
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<LL> a(n + 1, 0);
    for (int i = 1;i <= n;i ++) cin >> a[i];
    LL ans = inf;
    for (int i = 1;i <= n;i ++) {
        for (int j = 0;j < siz(p);j ++) {
            if (a[i] % p[j] != 0) {
                ans = min(ans, p[j]);
                break;
            }
            while (a[i] % p[j] == 0) a[i] /= p[j];
        }
    }
    cout << ans << '\n';
}

int main() {
    Euler();
    // LL ans = 1;
    // for (int i = 0;i < 100;i ++) {
    //     ans *= p[i];
    //     cout << ans << '\n';
    // }
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}