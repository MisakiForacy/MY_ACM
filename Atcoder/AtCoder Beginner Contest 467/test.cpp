#include <bits/stdc++.h>

using namespace std;

using LL = long long;

void solve() {
    int n;
    cin >> n;
    vector<LL> a(n + 1), pre(n + 1, 0), suf(n + 2, 0);
    for (int i = 1;i <= n;i ++) cin >> a[i];
    for (int i = 1;i <= n;i ++) pre[i] = pre[i - 1] + a[i];
    for (int i = n;i >= 1;i --) suf[i] = suf[i + 1] + a[i];
    int mid = n / 2 + 1;
    LL Ls = 0, Rs = 0;
    for (int i = 1;i <= n;i ++) {
        if (i < mid) 
            Ls += a[i];
        if (i > mid)
            Rs += a[i];
    }
    int ok, l = 1, r = n;
    if (n & 1) {
        ok = 0;
        l = mid - 1, r = mid + 1;
        while (l >= 1 && r <= n) {
            if (pre[l] != suf[r]) {
                if (pre[l] > suf[r]) ok = 1;
                break;
            }
            l --, r ++;
        }
    } else {
        ok = 1;
        l = mid - 1, r = mid + 1;
        while (l >= 1 && r <= n) {
            if (pre[l] != suf[r]) {
                if (pre[l] < suf[r]) ok = 0;
                break;
            }
            l --, r ++;
        }
    }
    cout << (ok ? "YES\n" : "NO\n");
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T;
    cin >> T;
    while (T --) solve();
}