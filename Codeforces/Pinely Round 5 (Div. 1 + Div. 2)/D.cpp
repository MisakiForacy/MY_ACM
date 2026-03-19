#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

#define LOG 20

#define x first 
#define y second 

using namespace std;
using LL = long long;

const LL inf = 1e15;
const int N = 2e5 + 10;

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

void solve () {
    int n;
    cin >> n;
    vector<LL> a(n + 1);
    vector<LL> cnt(n + 1, 0), pre(n + 2, 0);
    for (int i = 1;i <= n;i ++) cin >> a[i];
    LL dp[n + 1], D[n + 1][2];
    memset(dp, 0x3f, sizeof dp);
    memset(D, 0x3f, sizeof D);
    D[0][0] = D[0][1] = 0;
    for (int )
    cout << min(dp[n][0], dp[n][1]) << '\n';
}

int main () {
    // freopen ("in", "r", stdin);
    // freopen ("out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve ();
}