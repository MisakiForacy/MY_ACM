#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> tot(n + 1, 0);
    vector<double> p(n + 1);
    for (int i = 1;i <= n;i ++) cin >> p[i];
    double res = 0;
    while (1) {
        int id, cnt;
        cin >> id >> cnt;
        if (id == 0) break;
        tot[id] += cnt;
        res += p[id] * cnt;
    }
    for (int i = 1;i <= n;i ++) cout << tot[i] << '\n';
    cout << res << '\n';
}

int main() {
    cout << fixed << setprecision(2);
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}