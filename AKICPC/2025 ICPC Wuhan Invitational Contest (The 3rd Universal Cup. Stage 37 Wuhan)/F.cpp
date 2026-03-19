#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())
#define lowbit(x) ((x) & (-x))
#define x first 
#define y second
using namespace std;
using LL = long long;

mt19937_64 rng(time(0));

const int N = 2e5 + 10;
const LL inf = 1e15 + 10;
const LL MOD = 998244353;

LL qmi(LL a, LL k) {
    LL res = 1;
    while (k) {
        if (k & 1) (res *= a) %= MOD;
        (a *= a) %= MOD;
        k >>= 1;
    }
    return res;
}

void solve() {
    LL n, m;
    cin >> n >> m;
    vector<pair<LL, LL>> p;
    for (int i = 1;i <= n;i ++) {
        LL a, b;
        cin >> a >> b;
        p.push_back({a, b});
    }
    sort(all(p), [&](pair<LL, LL> x, pair<LL, LL> y) {
        return x.y < y.y;
    });
    LL lst = 0;
    LL ans = 0, cur = 0;
    for (int i = 0;i < siz(p);i ++) {
        LL add = p[i].x / (m - lst);
        lst = (lst + add) % m;
        if (i == 0 || )
    }
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}