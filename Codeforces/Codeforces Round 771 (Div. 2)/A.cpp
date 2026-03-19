#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1, 0);
    for (int i = 1;i <= n;i ++) cin >> a[i];
    int Mi = n, l = n + 1, r = 0;
    for (int i = n;i >= 1;i --) {
        if (a[i] < Mi) Mi = a[i];
        else continue;
        for (int j = 1;j < i;j ++) {
            if (a[j] > a[i]) {
                l = j;
                r = i;
                break;
            }
        }
    }
    for (int i = 1;i < l;i ++) cout << a[i] << ' ';
    for (int i = r;i >= l;i --) cout << a[i] << ' ';
    if (l < r) for (int i = r + 1;i <= n;i ++) cout << a[i] << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}