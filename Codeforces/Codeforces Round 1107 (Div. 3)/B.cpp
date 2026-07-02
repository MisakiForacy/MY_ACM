#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;

using LL = long long;

void solve() {
    LL x, y;
    cin >> x;
    int len = 0;
    while (x) {
        len ++;
        x /= 10;
    }
    cout << 1;
    for (int i = 0;i < len - 1;i ++) cout << 0;
    cout << 1 << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}
