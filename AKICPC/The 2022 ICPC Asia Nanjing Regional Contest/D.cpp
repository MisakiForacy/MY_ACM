#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())
using namespace std;
using LL = long long;

/*
6
7
1 1 1 -1 1 1 -1
4
1 0 -1 0
4
0 -1 -1 0
1
0
2
0 0
1 
-1
*/

void solve() {
    int n, k, m, c, d;
    cin >> n >> k >> m >> c >> d;
    vector<LL> a(n + 1, 0);
    for (int i = 1;i <= n;i ++) cin >> a[i];
    auto check = [&](LL x) -> int {
        int cnt = 0;
        for (int i = 1;i <= n;i ++) {
            cnt += a[i] <= x;
        }
        if (cnt >= k) return 1;
        for (int i = 1;i <= n - m + 1;i ++) {
            
        }
    };
    LL cur = 0;
    for (int j = 62;j >= 0;j --) {
        LL val = cur + (1LL << j);
        if (check(val)) cur += 1LL << j;
    }
    cout << cur << '\n';
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.tix", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}