#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    int n;
    cin >> n;
    vector<LL> a(2 * n + 1, 0);
    int p = 1;
    for (int i = n;i >= 1;i --) {
        LL Mx = (2 * n - p) / i;
        a[p] = i;
        for (int j = Mx;j >= 1;j --) {
            if (a[p + j * i]) continue;
            a[p + j * i] = i;
            break;
        }
        while (p <= 2 * n && a[p]) p ++;
    }
    for (int i = 1;i <= 2 * n;i ++) cout << a[i] << " \n"[i == 2 * n];
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T;
    cin >> T;
    while (T --) solve();
}