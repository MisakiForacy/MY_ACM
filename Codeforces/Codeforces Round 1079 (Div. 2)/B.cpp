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
    vector<int> a(n + 1, 0), p(n + 1, 0), pos(n + 1, 0);
    for (int i = 1;i <= n;i ++) cin >> p[i], pos[p[i]] = i;
    for (int i = 1;i <= n;i ++) cin >> a[i];
    int R = 1;
    for (int i = 1;i <= n;i ++) {
        if (pos[a[i]] < R) {
            cout << "NO\n";
            return;
        } 
        R = max(R, pos[a[i]]);
    }
    cout << "YES\n";
}   

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}