#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    int n;
    cin >> n;
    vector<LL> a(n + 1);
    for (int i = 1;i <= n;i ++) cin >> a[i];
    sort(a.begin() + 1, a.end());
    a.push_back(-1);
    LL A = 0, B = 0;
    LL r = 1;
    map<LL, LL> mp;
    priority_queue<pair<int, int>> que;
    for (int i = 1;i <= n;i ++) {
        LL len = 1;
        while (a[i] == a[i + 1]) i ++, len ++;
        if (a[i] & 1) {
            que.push({len, a[i]});
        } else {
            mp[a[i]] = len;
        }
    }
    while (que.size()) {
        auto [x, y] = que.top();
        que.pop();
        if (r) A += x;
        else   B += x;
        if (y - 1) mp[y - 1] += x;
        r ^= 1;
    }
    for (auto [k, v] : mp) {
        A += k * v / 2, B += k * v / 2;
    }
    cout << A << ' ' << B << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T;
    cin >> T;
    while (T --) solve();
}