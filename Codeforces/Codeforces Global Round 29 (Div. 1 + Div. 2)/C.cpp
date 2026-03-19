#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 4, 0), pos;
    for (int i = 2;i <= n + 1;i ++) {
        char c; cin >> c;
        a[i] = c - '0';
    }
    int ok = 1;
    for (int i = 2;i <= n + 1;i ++) {
        if (a[i] == 0 && a[i - 1] + a[i - 2] + a[i + 1] + a[i + 2] == 4) {
            ok = 0;
        }
    }
    for (int i = 2;i <= n + 1;i ++) {
        if (a[i] == 0) {
            if (a[i - 1] == 1 && (a[i - 2] == 1 || i - 2 < 2)) {
                int cnt = 1;
                while (i + 2 <= n + 1 && a[i + 1] == 1 && a[i + 2] == 0) {
                    i += 2;
                    cnt ++;
                }
                if (a[i + 1] == 1 && (a[i + 2] == 1 || i + 2 > n + 1)) {
                    if (cnt & 1) ok = 0;
                }
            }
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