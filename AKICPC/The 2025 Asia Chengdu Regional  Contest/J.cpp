#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve () {
    LL n, m, k, b, cnt = 0;
    cin >> n >> m >> k >> b;
    for (int i = 1;i <= n;i ++) {
        vector<LL> a(m + 1, 0);
        LL sum = 0;
        for (int j = 1;j <= m;j ++) {
            cin >> a[j];
            sum += a[j];
        }
        if (sum >= k) {
            cnt ++;
        } else if (b > 0) {
            sum = 0;
            for (int j = 1;j <= m;j ++) {
                if (a[j] >  0) a[j] -= 1;
                else if (a[j] <= 0) a[j] += 1;
                sum += a[j];
            }
            if (sum >= k) {
                cnt ++;
                b --;
            }
        }
    }
    cout << cnt << '\n';
}

/*
2
5 3 2 1
-3 0 3
2 -2 -1
1 1 1
0 0 0
-1 -1 -1
3 2 -1 1
-1 -2 
-3 -3
1 -3
*/

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve ();
}