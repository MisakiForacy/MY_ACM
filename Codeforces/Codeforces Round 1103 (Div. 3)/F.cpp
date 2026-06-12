#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

#define lowbit(x) ((x) & (-x))

using namespace std;
using LL = long long;

const LL inf = 1e15;

const int N = 5e5 + 10;

const int MOD = 1e9 + 7;

vector<LL> P, S(N, 0);

void init() {
    S[1] = 1;
    for (int i = 2;i < N;i ++) {
        if (!S[i]) P.push_back(i), S[i] = i;
        for (int j = 0;j < siz(P) && P[j] * i < N;j ++) {
            S[P[j] * i] = P[j];
            if (i % P[j] == 0) break;
        }
    }
}

void solve() {
    LL n, x, v;
    cin >> n >> x;
    map<int, LL> mp;
    for (int i = 1;i <= n;i ++) {
        cin >> v;
        while (v > 1) {
            int p = S[v];
            while (v % p == 0) {
                v /= p;
                mp[p] ++;
            }
        }
    }
    LL ans = 1;
    for (auto [k, v] : mp) {
        ans *= v + 1;
        ans %= MOD;
    }
    cout << ans << '\n';
}

int main() {
    init();
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}