#include <bits/stdc++.h>

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
        queue<int> q;
        for (int i = 0;i < n;i ++) {
            if (b[i] > b[i + 1] && b[i] + b[i + 1] <= x) {
                q.push(i);
            }
        }
        while (siz(q)) {
            int i = q.front();
            q.pop();
            if (b[i] <= b[i + 1] || b[i] + b[i + 1] > x) continue;
            swap(b[i], b[i + 1]);
            b[i + 1] += b[i];
            if (i > 0 && b[i] > b[i - 1] && b[i] + b[i - 1] <= x) q.push(i - 1);
            if (i < n && b[i + 1] > b[i + 2] && b[i + 1] + b[i + 2] <= x) q.push(i + 1);
        }
        for (int i = 1;i < n;i ++) if (b[i] < b[i - 1]) return 0;
        return 1;
    };
    while (lo < hi) {
        LL mid = lo + hi + 1 >> 1;
        if (!check(mid))
            hi = mid - 1;
        else    
            lo = mid;
    }
    cout << hi << '\n';
}

int main() {
    // ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}