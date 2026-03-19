#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

#define x first 
#define y second 

#define LOG 60

using namespace std;
using LL = long long;

const LL inf = 1e15;

void solve() {
    LL n, m;
    cin >> n >> m;
    LL M = m * 10007;
    vector<LL> R(61, 1), D(61, 1); 
    // R[i] 表示 2^i 个1组成的数，D[i] 表示 10^(2^(i))
    // R[i] = R[i - 1] * D[i - 1] + R[i - 1];
    auto qmi = [&](LL a, LL k) -> LL {
        LL res = 1;
        while (k) {
            if (k & 1) (res *= a) %= M;
            (a *= a) %= M;
            k >>= 1;
        }
        return res;
    };
    for (int i = 0;i <= 60;i ++) D[i] = qmi(10, 1LL << i);
    for (int i = 1;i <= 60;i ++) {
        R[i] = (R[i - 1] * D[i - 1] + R[i - 1]) % M;
    }
    // for (int i = 1;i <= 60;i ++) cout << R[i] << ' ';
    // // cout << '\n';
    vector<LL> c(n + 1), l(n + 1);
    for (int i = 1;i <= n;i ++) cin >> c[i] >> l[i];
    LL N = 0;
    for (int i = 1;i <= n;i ++) {
        LL base = 0;
        for (int j = 60;j >= 0;j --) {
            if (l[i] >> j & 1) {
                base *= D[j];
                base %= M;
                base += R[j];
                base %= M;
            }
        }
        for (int j = 60;j >= 0;j --) {
            if (l[i] >> j & 1) {
                N *= D[j];
                N %= M;
            }
        }
        N += base * c[i] % M;
        N %= M;
        // cout << N << '\n';
    }
    cout << N / m << '\n';
}

int main() {
    // ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}