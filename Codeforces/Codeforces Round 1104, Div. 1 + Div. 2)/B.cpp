#include <bits/stdc++.h>

#define siz(x) ((int)x.size())

#define all(x) begin(x),end(x)

using namespace std;

using LL = long long;

void solve() {
    int n;
    cin >> n;
    vector<LL> a(n), b(n);
    for (int i = 0;i < n;i ++) cin >> a[i];
    for (int i = 0;i < n;i ++) cin >> b[i];
    int cnt = 0;
    for (int i = 0;i < n;i ++) {
        for (int j = n - 1;j >= 0;j --) {
            if (a[j] > b[j]) {
                while (j + 1 < n && a[j] > b[j]) {
                    swap(a[j], a[j + 1]);
                    cnt ++;
                    j ++;
                }
                break;
            }
        }
        for (int i = 0;i < n;i ++) cout << a[i] << ' ';
        cout << '\n';
    }
    for (int i = 0;i < n;i ++) if (a[i] > b[i]) {
        cout << -1 << '\n';
        return;
    }
    cout << cnt << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}