#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const LL N = 1e7;

vector<int> use = {0}, p(N + 1, 0);

void init() {
    for (LL x = 1;x <= N;x ++) {
        for (LL y = x + 1;y * y + x * x <= N;y ++) {
            if (x * x + y * y > N) break;
            p[x * x + y * y] += 1;
        }
    }
    for (int i = 1;i <= N;i ++) if (p[i] == 1) use.push_back(i);
}

void solve() {
    int n;
    cin >> n;
    int m = upper_bound(use.begin(), use.end(), n) - use.begin() - 1;
    cout << m << '\n';
    for (int i = 1;i <= m;i ++) cout << use[i] << ' ';
    cout << '\n';
}

int main() {
    init();
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}