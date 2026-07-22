#include <bits/stdc++.h>

using namespace std;

using LL = long long;

const int N = 30;

const int off = N;

int ans = 0;
int n;
int a[N], px[2 * N], qx[2 * N], h[N];

void dfs(int pos) {
    if (pos > n) {
        if (!ans) {
            for (int i = 1;i <= n;i ++) {
                cout << a[i] << ' ';
            }
            cout << '\n';
        }
        ans ++;
    }
    for (int i = 1;i <= n;i ++) {
        if (!h[i] && !px[pos - i + off] && !qx[pos + i]) {
            h[i] = 1;
            px[pos - i + off] = 1;
            qx[pos + i] = 1;
            a[pos] = i;
            dfs(pos + 1);
            h[i] = 0;
            px[pos - i + off] = 0;
            qx[pos + i] = 0;
        }
    }
}

void solve() {
    cin >> n;
    dfs(1);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}