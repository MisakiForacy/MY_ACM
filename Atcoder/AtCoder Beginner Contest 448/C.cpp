#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

#define x first 
#define y second 

#define LOG 60

using namespace std;
using LL = long long;

const LL inf = 1e15;
const LL MOD = 1e9 + 7;

void solve() {
    LL n, q;
    cin >> n >> q;
    vector<pair<LL, LL>> a(n + 1);
    for (int i = 1;i <= n;i ++) cin >> a[i].x, a[i].y = i;
    sort(a.begin() + 1, a.end());
    while (q --) {
        int k;
        cin >> k;
        vector<int> b(k);
        for (int i = 0;i < k;i ++) cin >> b[i];
        for (int i = 1;i <= 6;i ++) {
            int ok = 1;
            for (int j = 0;j < k;j ++) {
                if (a[i].y == b[j]) ok = 0;
            }
            if (ok) {
                cout << a[i].x << '\n';
                break;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}