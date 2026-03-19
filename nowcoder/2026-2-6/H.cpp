#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;

void solve() {
    LL n;
    cin >> n;
    vector<LL> a(n + 1), pre(n + 1);
    map<int, int> idx;
    for (int i = 1;i <= n;i ++) cin >> a[i];
    for (int i = 1;i <= n;i ++) {
        pre[i] = idx[a[i]];
        idx[a[i]] = i;
    }
    LL Ans = 0;
    for (int i = 1;i <= n;i ++) {
        LL v1 = (n - i + 1) * (n - i + 2) / 2;
        LL v2 = i - pre[i];
        Ans += v1 * v2;
    }
    cout << Ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}