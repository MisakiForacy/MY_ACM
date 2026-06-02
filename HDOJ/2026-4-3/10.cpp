#include <bits/stdc++.h>

using namespace std;
using LL = long long;

const LL mod = 998244353;

const int N = 2005;

LL C[5005][5005];
double lgC[5005][5005];
 
void init() {
    for (int i = 0;i <= 5000;i ++) {
        C[i][0] = lgC[i][0] = 1;
        for (int j = 1;j <= i;j ++) {
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1] % mod;
            lgC[i][j] = lgC[i][j - 1] + log(i - j + 1) - log(j);
        }
    }
}

struct node
{
    LL u, v, n, m;
    bool operator < (const node&T) const {
        return lgC[n][m] < lgC[T.n][T.m];
    }
};

int f[N];

int find(int x) {
    if (f[x] != x) f[x] = find(f[x]);
    return f[x];
}

void merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return;
    if (u > v) swap(u, v);
    f[u] = v;
};

void solve() {
    int n;
    cin >> n;
    vector<LL> a(n + 1);
    for (int i = 1;i <= n;i ++) cin >> a[i];
    sort(a.begin() + 1, a.end());
    LL ans = 0;
    for (int i = 2;i <= n;i ++) 
        ans += C[a[i]][a[i - 1]], ans %= mod;
    cout << ans << '\n';
}

int main() {
    init();
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}