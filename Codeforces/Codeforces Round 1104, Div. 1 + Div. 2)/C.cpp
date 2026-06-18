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
    LL sum = 0, mx = 0;
    vector<LL> a(n + 1);
    for (int i = 0;i < n;i ++) cin >> a[i], sum += a[i], mx = max(mx, a[i]);
    a[n] = 1e17;
    // cout << "ok" << '\n';
    LL lo = mx, hi = sum;
    auto check = [&](LL x) -> int {
        vector<LL> b = a, vis(n, 0);
        stack<LL> stk, tp;
        for (int i = 0;i < n;i ++) {
            if (stk.empty()) {
                stk.push(b[i]);
            } else if (b[i] < stk.top()) {
                if (b[i] + stk.top() <= x) {
                    LL use = b[i] + stk.top();
                    stk.pop();
                    stk.push(b[i]);
                    stk.push(use);
                } else {
                    return 0;
                }
            } else {
                stk.push(b[i]);
            }
        }
        return 1;
    };
    // cout << check(26) << '\n';
    // cout << check(14) << '\n';
    while (lo < hi) {
        LL mid = lo + hi >> 1;
        if (check(mid))
            hi = mid;
        else    
            lo = mid + 1;
    }
    cout << lo << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}