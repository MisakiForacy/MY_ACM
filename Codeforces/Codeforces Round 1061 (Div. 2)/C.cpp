#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())
#define lowbit(x) ((x) & (-x))
using namespace std;
using LL = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<LL> a(n + 1, 0), b(n + 1, 0);
    for (int i = 1;i <= n;i ++) cin >> a[i];
    vector<int> v(n + 1, 0), p(n + 1, 0);
    for (int i = 1;i <= n;i ++) {
        b[i] = a[i] / 4;
        p[0] ++, p[b[i] + 1] --;
        for (int j = 1;j * j <= a[i];j ++) {
            if (a[i] % j) continue;
            int x = j, y = a[i] / j;
            if (x > b[i]) v[x] ++;
            if (x != y && y > b[i]) v[y] ++;
        }
    }
    for (int i = 1;i <= n;i ++) p[i] += p[i - 1];
    for (int i = 1;i <= n;i ++) p[i] += v[i];
    for (int i = n;i >= 1;i --) {
        if (p[i] >= n - k) {
            cout << i << '\n';
            return;
        }
    }
}

int main() {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}