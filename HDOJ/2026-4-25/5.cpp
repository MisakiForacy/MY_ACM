#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1, 0), dp(n + 1, 0);
    stack<pair<int, int>> stk;
    for (int i = 1;i <= n;i ++) {
        cin >> a[i];
        if (stk.size() && a[i] == stk.top().first) {
            stk.push({a[i], stk.top().second + 1});
        } else {
            stk.push({a[i], 1});
        }
        if (stk.top().second == k) {
            for (int i = 1;i <= k;i ++) stk.pop();
        }
    }
    vector<int> p;
    while (stk.size()) p.push_back(stk.top().first), stk.pop();
    reverse(p.begin(), p.end());
    cout << p.size() << '\n';
    for (auto x : p) cout << x << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}