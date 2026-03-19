#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

#define x first 
#define y second 

using namespace std;
using LL = long long;
using PII = pair<LL, LL>;

const int N = 200005;

void solve() {
    LL n, m, k;
    cin >> n >> m >> k;
    LL L = k - 1, R = n - k;
    if (L < R) swap(L, R);
    LL Ans = 1;
    for (LL i = 0;i <= R;i ++) {
        LL need = max(0LL, i * 2 - 1);
        LL rst = max(1LL, i);
        if (need > m) break;
        LL t = m - need;
        if (rst > t) Ans = max(Ans, i + t + 1);
        else {
            LL cur = 0;
            for (int j = 60;j >= 0;j --) {
                if (cur + (1LL << j) > L) continue;
                LL tmp = cur + (1LL << j);
                if (tmp <= rst) cur = tmp;
                else {
                    LL step = tmp * 2 - rst;
                    if (step <= t) cur = tmp;
                }
            }
            Ans = max(Ans, i + cur + 1);
        }
    }
    cout << Ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}