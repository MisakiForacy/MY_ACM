#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<LL> a(n + 1);
    for (int i = 1;i <= n;i ++) cin >> a[i];
    int lo = 1, hi = n - k;
    auto check = [&](int x) -> int {
        for (int i = 1;i <= n - k - x;i ++) {
            vector<int> a(k + 1, 0);
            for (int j = i;j <= )    
        }
    };
    while (lo < hi) {
        int mid = lo + hi >> 1;
        if (check(mid))
            lo = mid + 1;
        else 
            hi = mid;
    }
    cout << lo << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}