#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())
using namespace std;
using LL = long long;

void solve() {
    int l, a, b;
    cin >> l >> a >> b;
    int Mx = a;
    for (int i = 1;i <= 5000;i ++) {
        a = (a + b) % l;
        Mx = max(Mx, a);
    }
    cout << Mx << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}