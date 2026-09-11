#include <bits/stdc++.h>

#define x first 

#define y second 

#define siz(x) ((int)x.size())

#define all(x) begin(x),end(x)

using namespace std;

using LL = long long;

void solve() {
    int n;
    cin >> n;
    vector<LL> f(n + 1, 0), p(n + 1), use(n + 1), alls;
    vector<char> op(n + 1);
    for (int i = 1;i <= n;i ++) {
        cin >> op[i] >> p[i];
        alls.push_back(p[i]);
    }
    sort(all(alls));
    alls.erase(unique(all(alls)), alls.end());
    for (int i = 1;i <= n;i ++) {
        use[i] = lower_bound(all(alls), p[i]) - p.begin() + 1;
    }
    auto ask = [&]()
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}