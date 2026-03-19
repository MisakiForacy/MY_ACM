#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

#define x first 
#define y second 

using namespace std;
using LL = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 1;i <= n;i ++) {
        if (i & 1) {
            for (int j = 1;j <= m;j ++) {
                cout << (j & 1 ? '/' : '\\');
            }
        } else {
            for (int j = 1;j <= m;j ++) {
                cout << (j & 1 ? '\\' : '/');
            }
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}