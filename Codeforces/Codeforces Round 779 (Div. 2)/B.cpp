#include <bits/stdc++.h>

#define x first 
#define y second 

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;

const LL N = 1005;
const LL MOD = 998244353;

LL fac[N];

void init() {
    fac[0] = 1;
    for (int i = 1;i < N;i ++) fac[i] = fac[i - 1] * i % MOD;
}

void solve() {
    int n;
    cin >> n;
    if (n & 1) {
        cout << 0 << '\n';
    } else {
        cout << fac[n / 2] * fac[n / 2] % MOD << '\n';
    }
}

int main() {
    init();
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}