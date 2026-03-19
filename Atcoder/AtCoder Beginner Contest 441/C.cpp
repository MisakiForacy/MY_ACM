#include <bits/stdc++.h>

#define x first 
#define y second 

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;

void solve() {
    LL n, k, x;
    cin >> n >> k >> x;
    vector<LL> a(n), b(n, 0);
    for (int i = 0;i < n;i ++) cin >> a[i];
    sort(a.begin(), a.end());
    LL Sm = 0;
    for (int i = 0;i < k;i ++) b[i] = a[i], Sm += a[i];
    if (Sm < x) {
        cout << -1 << '\n';
    } else {
        LL Sm = 0, Cnt = 0;
        for (int i = n - 1;i >= 0;i --) {
            Sm += b[i];
            Cnt += 1;
            if (Sm >= x) break;
        }
        cout << Cnt << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}