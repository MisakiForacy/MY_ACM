#include <bits/stdc++.h>

#define siz(x) ((int)x.size())

#define all(x) begin(x),end(x)

using namespace std;

using LL = long long;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> p(n + 1, vector<int> (n + 1));
    for (int i = 1;i <= n;i ++) {
        for (int j = i + 1;j <= n;j ++) {
            cin >> a[i][j];
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}
