#include <bits/stdc++.h>

#define siz(x) ((int)x.size())

#define all(x) begin(x),end(x)

using namespace std;

using LL = long long;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n), b(n), posa(n + 1), posb(n + 1), use(n + 1, 0);
    for (int i = 0;i < n;i ++) cin >> a[i], posa[a[i]] = i + 1;
    for (int i = 0;i < n;i ++) cin >> b[i], posb[b[i]] = i + 1;
    int i = 0, j = 0;
    while (1) {
        while (use[a[i]]) i ++;
        while (use[b[j]]) j ++;
        if (a[i] == b[j] && a[i] != x) {
            cout << "NO\n";
            return;
        }
        if (posa[a[i]] < posa[x] && posb[a[i]] < posb[x]) {
            use[a[i]] = 1;
            i ++;
        } else if (posa[b[j]] < posa[x] && posb[b[j]] < posb[x]) {
            use[b[j]] = 1;
            j ++;
        } else {
            
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}