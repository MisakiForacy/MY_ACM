#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;

void solve() {
    LL n, k;
    cin >> n >> k;
    LL cur = 0;
    for (int j = 31;j >= 0;j --) {
        LL Tp = cur + (1LL << j);
        if (Tp - Tp / n < k) continue;
        cur = Tp;
    }
    cout << cur + 1 << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T;
    cin >> T;
    while (T --) solve();
}