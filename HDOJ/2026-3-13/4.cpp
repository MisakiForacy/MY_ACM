#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;

const int N = 1e5 + 10;

vector<int> P = {0}, S(N, 0);

void pri() {
    for (int i = 2;i < N;i ++) {
        if (!S[i]) P.push_back(i);
        for (int j = 1;j < siz(P) && i * P[j] < N;j ++) {
            S[i * P[j]] = 1;
            if (i % P[j] == 0) break;
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> p(2 * n + 1, 0);
    for (int i = 1;i <= n;i ++) cin >> p[i], p[i + n] = p[i];
    int mx = 0;
    auto cal = [&]() -> void {
        vector<vector<int>> dp(2 * n + 2, vector<int> (11, 2 * n + 5));
        for (int j = 1;j <= 10;j ++) {
            for (int i = 2 * n;i >= 1;i --) {
                dp[i][j] = (p[i] >= j ? i : dp[i + 1][j]);
            }
        }
        for (int i = 1;i <= n;i ++) {
            int cur = i, idx = 0;
            while (cur - i + 1 <= n) {
                int nxt = idx;
                while (P[nxt] - P[idx] <= p[cur]) nxt ++;
                idx = nxt - 1;
                if (P[nxt] - P[idx] > 10) break;
                cur = dp[cur + 1][P[nxt] - P[idx]];
            }
            mx = max(mx, P[idx]);
        }
    };
    cal();
    reverse(p.begin() + 1, p.end());
    cal();
    cout << mx << '\n';
}

int main() {
    pri();
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}