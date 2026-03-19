#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())
#define lowbit(x) ((x) & (-x))
#define nl cout << '\n';
#define debug(x) cerr << #x << ':' << x << ' '
#define x first
#define y second
using namespace std;
using LL = long long;

const int N = 2e5 + 10;
const LL inf = 1e15;

mt19937_64 rng(time(0));

void fxy_ac() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1), p(n + 1, 0);
    a[0] = n + 1, p[0] = 1;
    for (int i = 1;i <= n;i ++) a[i] = i;
    if (k == 0) {
        for (int i = 1;i <= n;i ++) cout << a[i] << ' ';
        cout << '\n';
        return;
    }
    vector<set<pair<int, int>>> dp(n + 1);
    dp[0].insert({0, 0});
    vector<vector<int>> used(n + 1, vector<int> (k + 1, 0));
    used[0][0] = 1;
    for (int i = 1;i < n;i ++) {
        for (int j = 0;j < i;j ++) {
            LL val = (i - j) * (n - i);
            // for (auto [x, id] : dp[j]) {
            for (int s = 0;s + val <= k;s ++) {
                // dp[i].insert({x + val, j});
                if (used[j][s]) {
                    used[i][s + val] = 1;
                    dp[i].insert({s + val, j});
                    if (s + val == k) {
                        int cur = i, nxt, now = s + val, dat = val;
                        while (cur) {
                            p[cur] = 1;
                            for (auto [xx, idx] : dp[cur]) {
                                if (now == xx) {
                                    nxt = idx;
                                    break;
                                }
                            }
                            dat = (cur - nxt) * (n - cur);
                            now -= dat;
                            cur = nxt;
                        }
                        // for (int i = 1;i <= n;i ++) cout << p[i] << ' ';
                        // cout << '\n';
                        LL lo = 1, hi = n;
                        for (int i = 1;i <= n;i ++) {
                            if (p[i]) {
                                cout << hi -- << ' ';
                            } else {
                                cout << lo ++ << ' ';
                            }
                        }
                        cout << '\n';
                        return;
                    }
                }
            }
        }
    }
    cout << 0 << '\n';
}

void brute() {

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) {
        fxy_ac();
        // brute();
    }
}