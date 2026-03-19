#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())
#define lowbit(x) ((x) & (-x))
#define nl cout << '\n';
#define debug(x) cerr << #x << ':' << x << ' '
#define x first
#define y second
using namespace std;
using LL = long long;

const int N = 2e5 + 10;
const LL inf = 1e15;

mt19937_64 rng(time(0));

void fxy_ac() {
    const int MOD = 1e9 + 7;
    int n, Q, qcnt;
    char s[MAXN];
    ll dp[2][MAXN][MAXN][3];
    ll ans[MAXN][MAXN][MAXN];
    scanf("%d%d%s", &n, &Q, s + 1);
    qcnt = count(s + 1, s + n + 1, '?');
    int cur = 0;
    dp[cur][0][0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        int nxt = cur ^ 1;
        memset(dp[nxt], 0, sizeof dp[nxt]);
        char c = s[i];
        for (int j = 0; j <= i; ++j)
            for (int k = 0; j + k <= i; ++k)
                for (int last = 0; last < 3; ++last) if (dp[cur][j][k][last]) {
                    ll val = dp[cur][j][k][last];
                    for (int nxtc = 0; nxtc < 3; ++nxtc) if (nxtc != last) {
                        if (c != '?' && c != 'a' + nxtc) continue;
                        int nj = j + (nxtc == 0);
                        int nk = k + (nxtc == 1);
                        (dp[nxt][nj][nk][nxtc] += val) %= MOD;
                    }
                }
        cur = nxt;
    }
    for (int x = 0; x <= n; ++x)
        for (int y = 0; x + y <= n; ++y)
            for (int z = 0; x + y + z <= n; ++z) {
                ll sum = 0;
                for (int p = 0; p < 3; ++p)
                    sum += dp[cur][x][y][p];
                sum %= MOD;
                ans[x][y][z] = sum;
                if (x) (ans[x][y][z] += ans[x - 1][y][z]) %= MOD;
                if (y) (ans[x][y][z] += ans[x][y - 1][z]) %= MOD;
                if (z) (ans[x][y][z] += ans[x][y][z - 1]) %= MOD;
                if (x && y) (ans[x][y][z] -= ans[x - 1][y - 1][z]) %= MOD;
                if (x && z) (ans[x][y][z] -= ans[x - 1][y][z - 1]) %= MOD;
                if (y && z) (ans[x][y][z] -= ans[x][y - 1][z - 1]) %= MOD;
                if (x && y && z) (ans[x][y][z] += ans[x - 1][y - 1][z - 1]) %= MOD;
            }
    while (Q--) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        printf("%lld\n", (ans[x][y][z] + MOD) % MOD);
    }
}

void brute() {

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) {
        fxy_ac();
        // brute();
    }
}