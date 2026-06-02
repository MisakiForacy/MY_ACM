#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

void solve() {
    int n;
    cin >> n;
    vector<LL> a(n + 1), p(n + 1, 0);
    for (int i = 1;i <= n;i ++) cin >> a[i], p[i] = p[i - 1] + a[i];
    if (p[n] == 0) {
        for (int i = 1;i <= n;i ++) {
            if (p[i]) {
                cout << "YES\n";
                cout << 2 << '\n';
                cout << 1 << ' ' << i << '\n';
                cout << i + 1 << ' ' << n << '\n';
                return;
            }
        }
        cout << "NO\n";
    } else {
        cout << "YES\n";
        cout << 1 << '\n';
        cout << 1 << ' ' << n << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}