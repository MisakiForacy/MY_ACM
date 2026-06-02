#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;

void solve() {
    int n, m, tot = 0, f = 0;
    cin >> n >> m;
    if (n > m) swap(n, m), f = 1;
    vector<vector<int>> a(n, vector<int> (m));
    for (int i = 0;i < n;i ++) {
        for (int j = 0;j < m;j ++) {
            a[i][j] = tot ++;
        }
    }
    int mid = m / 2;
    for (int i = 0;i < n;i ++) {
        int j = mid + 2 + (m & 1);
        if (mid >= 2) {
            swap(a[i][mid], a[i][mid - 2]);
            swap(a[i][mid], a[i][mid - 1]);
            swap(a[i][mid], a[i][mid + 1]);
        }
        for (;j < m;j += 2) swap(a[i][j], a[i][m - j - 1]);
    }
    for (int i = 0;i < n - 1;i ++) {
        if (m < 4) swap(a[i][mid], a[i + 1][mid]);
    }
    for (int i = 0;i < n;i ++) {
        for (int j = 0;j < m - 1;j ++) {
            if ((a[i][j] + 1) % (n * m) == a[i][j + 1] || (a[i][j] - 1 + n * m) % (n * m) == a[i][j + 1]) {
                cout << "No\n";
                return;
            }
        }
    }
    for (int j = 0;j < m;j ++) {
        for (int i = 0;i < n - 1;i ++) {
            if ((a[i][j] + 1) % (n * m) == a[i + 1][j] || (a[i][j] - 1 + n * m) % (n * m) == a[i + 1][j]) {
                cout << "No\n";
                return;
            }
        }
    }
    if (f) {
        cout << "Yes\n";
        for (int j = 0;j < m;j ++) {
            for (int i = 0;i < n;i ++) {
                cout << a[i][j] << ' ';
            }
            cout << '\n';
        }
    } else {
        cout << "Yes\n";
        for (int i = 0;i < n;i ++) {
            for (int j = 0;j < m;j ++) {
                cout << a[i][j] << ' ';
            }
            cout << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}