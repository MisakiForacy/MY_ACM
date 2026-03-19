#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

#define x first 
#define y second 

#define LOG 60

using namespace std;
using LL = long long;

using M = vector<vector<LL>>;
M mat = {{10, 0}, {1, 1}};

const LL inf = 1e15;

LL qmi(LL x, LL k, LL p) {
    LL res = 1;
    while (k) {
        if (k & 1) res = res * x % p;
        x = x * x % p;
        k >>= 1;
    }
    return res;
}

M mul(M a, M b, LL p) {
    M c(2, vector<LL>(2));
    for (int i = 0;i < 2;i ++) {
        for (int j = 0;j < 2;j ++) {
            for (int k = 0;k < 2;k ++) {
                c[i][j] += a[i][k] * b[k][j] % p;
                c[i][j] %= p;
            }
        }
    }
    return c;
}

/*
[0, 1] * [[10, 0],   = [11, 1]
          [1, 1]] 
*/

M Mqmi(LL k, LL p) {
    M a = mat;
    M ret = {{1, 0}, {0, 1}};
    while (k) {
        if (k & 1) ret = mul(ret, a, p);
        a = mul(a, a, p);
        k >>= 1;
    }
    return ret;
}

void solve() {
    LL n, m;
    cin >> n >> m;
    LL Mod = m * 10007;
    // pre_{i-1} * 10^l + R(l) * c_i
    M mat(2, vector<LL> (2, 0));
    LL N = 0;
    LL suf = 0;
    vector<LL> c(n + 1), l(n + 1);
    for (int i = 1;i <= n;i ++) cin >> c[i] >> l[i];
    for (int i = n;i >= 1;i --) {
        M use = Mqmi(l[i], Mod);
        LL R = use[1][0] % Mod;
        N += R * c[i] % Mod * qmi(10, suf, Mod) % Mod;
        N %= Mod;
        suf += l[i];
        // cout << R << '\n';
        // // N = (N * qmi(10, l, Mod) % Mod + R * c % Mod) % Mod;
        // cout << N << '\n';
    }
    cout << N / m << '\n';
}

// A : floor(N / m) % 10007
// B : floor(N % (m * 10007) / m)

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}