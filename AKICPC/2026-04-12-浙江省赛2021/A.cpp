#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;

void solve() {
    LL a[5], b[5];
    LL s1 = 0, s2 = 0;
    for (int i = 0;i < 5;i ++) cin >> a[i], s1 += a[i];
    for (int i = 0;i < 5;i ++) cin >> b[i], s2 += b[i];
    if (s1 >= s2) {
        cout << "Blue\n";
    } else {
        cout << "Red\n";
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}