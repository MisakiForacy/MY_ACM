#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())
using namespace std;
using LL = long long;

void solve () {
    LL n, k;
    cin >> n >> k;
    vector<LL> q(n + 1), r(n + 1);
    for (int i = 1;i <= n;i ++) cin >> q[i];
    for (int i = 1;i <= n;i ++) cin >> r[i];
    sort(q.begin() + 1, q.end());
    sort(r.begin() + 1, r.end());
    int Ans = 0;
    for (int i = 1, j = n;i <= n;i ++) {
        if (j < 1) break;
        LL y = r[j] + 1, x = y * q[i] + r[j];
        while (j >= 1 && x > k) {
            j --;
            y = r[j] + 1, x = y * q[i] + r[j];
        }
        if (j >= 1) {
            Ans ++;
            j --;
        }
    }
    cout << Ans << '\n';
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve ();
}