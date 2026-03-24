#include <bits/stdc++.h>

#define x first 
#define y second 

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;

const LL inf = 1e15;

void solve() {
    LL n;
    cin >> n;
    vector<LL> a(n + 1);
    for (int i = 1;i <= n;i ++) cin >> a[i];
    vector<int> ls(n + 1, 0), rs(n + 1, n + 1);
    stack<int> stk;
    for (int i = 1;i <= n;i ++) {
        while (!stk.empty() && a[stk.top()]  < a[i]) stk.pop();
        ls[i] = stk.empty() ? 0 : stk.top();
        stk.push(i);
    }
    while (!stk.empty()) stk.pop();
    for (int i = n;i >= 1;i --) {
        while (!stk.empty() && a[stk.top()] <= a[i]) stk.pop();
        rs[i] = stk.empty() ? n + 1 : stk.top();
        stk.push(i);
    }
    map<int, vector<int>> p;
    for (int i = 1;i <= n;i ++) p[a[i]].push_back(i);
    for (auto &[k, v] : p) sort(all(v));
    LL ans = n * n;
    for (int i = 1;i <= n;i ++) {
        if (a[i] % 2 == 0) continue;
        // traversal in smaller range
        if (i - ls[i] < rs[i] - i) {
            // need to find a value in range [i + 1, rs[i] - 1] that satisfy equals a[i] - a[j] + 1
            int l = i + 1, r = rs[i] - 1;
            for (int j = ls[i] + 1;j < i;j ++) {
                int need = a[i] - a[j] + 1;
                if (!p.count(need)) continue;
                int cnt = upper_bound(all(p[need]), r) - lower_bound(all(p[need]), l);
                ans -= cnt * 2;
            }
        } else {
            int l = ls[i] + 1, r = i - 1;
            for (int j = i + 1;j < rs[i];j ++) {
                int need = a[i] - a[j] + 1;
                if (!p.count(need)) continue;
                int cnt = upper_bound(all(p[need]), r) - lower_bound(all(p[need]), l);
                ans -= cnt * 2;
            }
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}