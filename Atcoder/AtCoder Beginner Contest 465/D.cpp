#include <bits/stdc++.h>

#define all(x) begin(x),end(x)

#define siz(x) ((int)x.size())

using namespace std;

using LL = long long;

void solve() {
    LL x, y, k;
    cin >> x >> y >> k;
    LL cnt = 0;
    LL X = x, Y = y;
    LL cnt1 = 0, cnt2 = 0;
    while (X) {
        X /= k;
        cnt1 ++;
    }
    while (Y) {
        Y /= k;
        cnt2 ++;
    }
    if (cnt1 > cnt2) swap(cnt1, cnt2), swap(x, y);
    while (cnt1 < cnt2) {
        y /= k;
        cnt2 --;
        cnt ++;
    }
    while (x != y) {
        x /= k;
        y /= k;
        cnt += 2;
    }
    cout << cnt << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}
