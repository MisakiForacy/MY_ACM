#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

#define x first 
#define y second 

using namespace std;
using LL = long long;
using PLL = pair<LL, LL>;

const LL inf = 1e15;

const int N = 1e6 + 10;

vector<int> P, S(N, 0);
vector<LL> hs(N);

mt19937_64 rnd(time(0));

// 求解较复杂情况区间问题，可以尝试异或哈希

void pri() {
    S[1] = 1;
    for (int i = 2;i < N;i ++) {
        if (!S[i]) P.push_back(i), S[i] = i;
        for (int j = 0;j < siz(P) && i * P[j] < N;j ++) {
            S[i * P[j]] = min(P[j], S[i]);
            if (i % P[j] == 0) break;
        }
    }
}

void solve() {
    // f(pi(a)) == f(x)
    // 满足条件：pi(a) 质因子指数仅存在1 且 恰好等于x奇数指数质因子的乘积
    // 
    LL n, x;
    cin >> n >> x;
    vector<LL> a(n + 1), v(n + 1, 0);
    for (int i = 1;i <= n;i ++) cin >> a[i];
    map<LL, LL> use, pre;
    LL need = 0;
    while (S[x] != 1) {
        need ^= hs[S[x]];
        x /= S[x];
    }
    // cout << need << '\n';
    for (int i = 1;i <= n;i ++) {
        int Tp = a[i];
        while (S[Tp] != 1) {
            v[i] ^= hs[S[Tp]];
            Tp /= S[Tp];
        }
    }
    LL ans = 0;
    for (int i = 1;i <= n;i ++) v[i] ^= v[i - 1];
    for (int i = 0;i <= n;i ++) {
        ans += pre[v[i] ^ need];
        pre[v[i]] ++;
        // cout << "idx : " << i << " ANS : " << ans << " v[i] : " << v[i] << " v[i]^need : " << (v[i] ^ need) << '\n';
    }
    cout << ans << '\n';
}

int main() {
    pri();
    for (int i = 0;i < N;i ++) hs[i] = rnd();
    // cout << "DEBUG : \n";
    // for (int i = 1;i <= 10;i ++) cout << S[i] << ' ';
    // cout << '\n';
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}
