#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    sort(all(s));
    map<char, int> mp;
    for (auto c : s) mp[c] ++;
    int mx = 0;
    auto check = [&](int m, int x) -> int {
        int len = 0;
        if (x) {
            for (auto [k, v] : mp) {
                len += v / x;
            }
        } else return 1;
        return len >= m;
    };
    for (int i = 1;i <= k;i ++) {
        if (k % i == 0 && i <= n) {
            for (int j = 1;j <= n / i;j ++) {
                if (check(i, j)) mx = max(mx, i * j);
            }
        }
    }
    cout << mx << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}