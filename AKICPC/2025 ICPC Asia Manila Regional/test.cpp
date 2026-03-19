#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    s = ' ' + s;
    int lo = 1, hi = n + 1;
    auto check = [&](int x) -> bool {
        int cur = x;
        for (int i = x;i <= n;i ++) {
            if (s[cur] == 'L') cur = max(0, cur - d);
            if (s[cur] == 'R') cur = min(n + 1, cur + d);
        }
        return (cur == n + 1);
    };
    while (lo < hi) {
        int mid = lo + hi >> 1;
        if (check(mid)) hi = mid;
        else lo = mid + 1;
    }
    cout << lo << '\n';
}

int main() {
    int T = 1;
    cin >> T;
    while (T --) solve();
}