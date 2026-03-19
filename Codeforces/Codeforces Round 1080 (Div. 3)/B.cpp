#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size()) 

#define x first 
#define y second 

using namespace std;
using LL = long long;

const int N = 2e5 + 10;
const LL inf = 1e18;

// 4 2 3 1 5

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1;i <= n;i ++) cin >> a[i];
    for (int i = 1;i <= n;i ++) {
        if (a[i] != i) {
            int j = i, ok = 0;
            while (j <= n) {
                if (i == a[j]) {
                    ok = 1;
                    break;
                }
                j *= 2;
            }
            if (j > n) j /= 2;
            while (j >= 1) {
                if (i == a[j]) {
                    ok = 1;
                    break;
                }
                if (j % 2) break;
                j /= 2;
            }
            if (!ok) {
                // cout << i << ' ';
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
    return;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}