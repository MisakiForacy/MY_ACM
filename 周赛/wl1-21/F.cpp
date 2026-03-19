#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

void solve() {
    LL a, b;
    cin >> a >> b;
    LL ans = 0;
    while (a && b && a + b >= 4) {
        if (a < b) swap(a, b);
        if (a - 1 > b) {
            LL d = min({(a - b) / 2, a / 3, b});
            ans += d;
            a -= d * 3;
            b -= d;
        } else {
            LL d = min(a, b) / 2;
            ans += d;
            a -= d * 2;
            b -= d * 2;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}