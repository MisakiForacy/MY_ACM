#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;

const LL N = 2e5 + 10;
const LL MOD = 998244353;

LL fac[N];

void init() {
    fac[0] = 1;
    for (int i = 1;i < N;i ++) fac[i] = fac[i - 1] * i % MOD;
}

void solve() {
    int n;
    cin >> n;
    vector<LL> a(n + 1, 0), b(n + 1, 0);
    for (int i = 1;i <= n;i ++) cin >> a[i];
    for (int i = 1;i <= n;i ++) cin >> b[i];
    LL Mi = *min_element(b.begin() + 1, b.end());
    LL L = 0, R = 0;
    for (int i = 1;i <= n;i ++) {
        if (a[i] > Mi) L ++;
        else R ++;
    }
    cout << fac[L] * fac[R] % MOD << '\n';
}

int main() {
    init();
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}