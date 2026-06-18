#include <bits/stdc++.h>

#define siz(x) ((int)x.size())

#define all(x) begin(x),end(x)

using namespace std;

using LL = long long;

void solve() {
    int n;
    cin >> n;
    vector<LL> a(n), b(n), vis(n + 1, 0), p(n, 0);
    for (int i = 0;i < n;i ++) cin >> a[i];
    for (int i = 0;i < n;i ++) cin >> b[i];
    int cnt = 0;
    for (int i = 0;i < n;i ++) {
        int ok = 0;
        for (int j = 0;j < n;j ++) {
            if (!vis[j] && b[j] >= a[i]) {
                vis[j] = 1;
                p[i] = j;
                ok = 1;
                break;
            }
        }
        if (!ok) {
            cout << -1 << '\n';
            return;
        }
    }
    for (int i = 0;i < n;i ++) {
        for (int j = 0;j < i;j ++) {
            if (p[j] > p[i]) cnt ++;
        }
    }
    cout << cnt << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}