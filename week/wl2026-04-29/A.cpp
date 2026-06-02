#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

#define x first 
#define y second 

using namespace std;
using LL = long long;

const LL mod = 998244353;

LL qmi(LL a, LL k) {
    LL res = 1;
    while (k) {
        if (k & 1) 
            res = res * a % mod;
        a = a * a % mod;
        k >>= 1;
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<LL> a(n + 1), p(n + 1, 0);
    for (int i = 1;i <= n;i ++) cin >> a[i];
    p[n] = 1;
    int k = 0;
    for (int i = n - 1;i >= 1;i --) {
        p[i] = p[i + 1] * 2 % mod + qmi(2, k);
        p[i] %= mod;
        k ++;
    }
    // for (int i = 1;i <= n;i ++) cout << p[i] << ' ';
    // cout << '\n';
    LL ans = 0;
    for (int i = 1;i <= n;i ++) {
        ans += p[i] % mod * a[i] % mod;
        ans %= mod;
    }
    cout << ans << '\n';
}

int main() {
    // int n;
    // cin >> n;
    // vector<int> a(n + 1, 0), p(n + 1, 0);
    // for (int i = 0;i < (1LL << n - 1);i ++) {
    //     vector<int> t;
    //     t.push_back(0);
    //     for (int j = 0;j < n - 1;j ++) {
    //         if (i >> j & 1) {
    //             t.push_back(j + 1);
    //         }
    //     }
    //     t.push_back(n);
    //     for (int j = 0;j < siz(t) - 1;j ++) {
    //         for (int k = 1;k <= t[j + 1] - t[j];k ++) {
    //             a[k] ++;
    //         }
    //     }
    // }
    // for (int i = 1;i <= n;i ++) cout << a[i] << ' ';
    // cout << '\n';
    // p[1] = 1;
    // for (int i = 2;i <= n;i ++) {
    //     p[i] = p[i - 1] * 2 + qmi(2, i - 2);
    //     p[i] %= mod;
    // }
    // for (int i = 1;i <= n;i ++) cout << p[i] << ' ';
    // cout << '\n';
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}