#include <bits/stdc++.h>

#define siz(x) ((int)x.size())

#define all(x) begin(x),end(x)

using namespace std;

using LL = long long;

const int N = 2e5 + 10;

const LL mod = 998244353;

vector<LL> fac(N), invfac(N);

LL qmi(LL x, LL k) {
    LL res = 1;
    while (k) {
        if (k & 1) res = res * x % mod;
        x = x * x % mod;
        k >>= 1;
    }
    return res;
}

LL inv(LL x) {
    LL res = 1;
    LL k = mod - 2;
    while (k) {
        if (k & 1) res = res * x % mod;
        x = x * x % mod;
        k >>= 1;
    }
    return res;
}

void init() {
    fac[0] = 1;
    for (int i = 1;i < N;i ++) fac[i] = fac[i - 1] * i % mod;
    invfac[N - 1] = inv(fac[N - 1]);
    for (int i = N - 2;i >= 0;i --) invfac[i] = (i + 1) * invfac[i + 1] % mod;
}

void solve() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    s = ' ' + s;
    vector<int> f(n + 1);
    for (int i = 1;i <= n;i ++) f[i] = i;
    auto find = [&](auto find, int x) -> int {
        return (f[x] == x ? f[x] : f[x] = find(find, f[x]));
    };
    auto merge = [&](int x, int y) -> void {
        x = find(find, x);
        y = find(find, y);
        if (x == y) return;
        if (x < y) swap(x, y);
        f[x] = y;
    };
    vector<vector<int>> g(n + 1);
    for (int i = 1;i <= m;i ++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
        merge(x, y);
    } 
    // cout << "ok\n";
    vector<map<char, int>> mp(n + 1);
    vector<int> sz(n + 1, 0);
    for (int i = 1;i <= n;i ++) mp[find(find, i)][s[i]] ++, sz[find(find, i)] ++;
    LL ans = 1, bad = 0;
    for (int i = 1;i <= n;i ++) {
        if (siz(mp[i])) {
            int ok = 0;
            LL tot = fac[sz[f[i]]], cnt = 1;
            for (auto [k, v] : mp[i]) {
                cnt *= invfac[v];
                cnt %= mod;
                if (v > 1) ok = 1;
            } 
            tot *= cnt;
            tot %= mod;
            bad += ok;
            ans *= tot;
            ans %= mod;
        }
    }
    if (!bad) (ans *= inv(2)) %= mod;
    cout << ans << '\n';
}

int main() {
    init();
    // ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}