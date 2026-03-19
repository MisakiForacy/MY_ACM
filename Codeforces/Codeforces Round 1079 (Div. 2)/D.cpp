#include <bits/stdc++.h>

#define x first 
#define y second 

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    LL ans = 0;
    vector<vector<int>> pos(n + 1);
    for (int i = 1;i <= n;i ++) {
        cin >> a[i];
        if (a[i] <= n) pos[a[i]].push_back(i);
    }
    for (int x = 1;x <= n;x ++) {
        if (!siz(pos[x])) continue;
        for (int y = 1;x * y <= n;y ++) {
            if (!siz(pos[y])) continue;
            int d = x * y;
            if (siz(pos[x]) < siz(pos[y])) {
                for (int i : pos[x]) {
                    int j = i + d;
                    if (j > n) continue;
                    if (a[j] == y) ans++;
                }
            } else {
                for (int j : pos[y]) {
                    int i = j - d;
                    if (i < 1) continue;
                    if (a[i] == x) ans++;
                }
            }
        }
    }
    cout << ans << '\n';
}   

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}