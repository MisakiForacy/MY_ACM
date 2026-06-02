#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> p(n + 1, 0);
    for (int i = 1;i <= n;i ++) {
        for (int j = 2;i * j <= n;j ++) {
            p[i] ++, p[i * j] ++;
        }
    }
    sort(p.begin() + 1,p.end(), greater());
    cout << p[k] << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}