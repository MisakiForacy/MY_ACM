#include <bits/stdc++.h>

#define x first 
#define y second 

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

void solve() {
    LL n, ax, ay, bx, by;
    cin >> n >> ax >> ay >> bx >> by;
    vector<pair<LL, LL>> p(n + 1);
    vector<LL> alls;
    alls.push_back(ax);
    alls.push_back(bx);
    for (int i = 1;i <= n;i ++) cin >> p[i].x, alls.push_back(p[i].x);
    for (int i = 1;i <= n;i ++) cin >> p[i].y;
    sort(alls.begin(), alls.end());
    alls.erase(unique(all(alls)), alls.end());
    for (int i = 1;i <= n;i ++) p[i].x = lower_bound(all(alls), p[i].x) - alls.begin();
    sort(p.begin() + 1, p.end());
    int m = siz(alls) - 1;
    // cout << m << '\n';
    vector<vector<LL>> dp(m + 1, vector<LL> (2, 1e15));
    vector<LL> Up(m + 1, 0), Down(m + 1, 1e10);
    for (int i = 1;i <= n;i ++) {
        // cout << p[i].x << ' ' << p[i].y << '\n';
        Up[p[i].x] = max(Up[p[i].x], p[i].y);
        Down[p[i].x] = min(Down[p[i].x], p[i].y);
        // cout << Up[p[i].x] << ' ' << Down[p[i].x] << '\n';
    }
    Up[0] = Down[0] = ay;
    Up[m] = Down[m] = by;
    // cout << "OK\n";
    dp[0][0] = dp[0][1] = 0;
    // for (int i = 0;i <= m;i ++) cout << Up[i] << ' ';
    // cout << '\n';
    // for (int i = 0;i <= m;i ++) cout << Down[i] << ' ';
    // cout << '\n';
    for (int i = 1;i <= m;i ++) {
        dp[i][0] = min(dp[i][0], dp[i - 1][1] + abs(Up[i - 1] - Up[i]) + Up[i] - Down[i]);
        dp[i][0] = min(dp[i][0], dp[i - 1][0] + abs(Down[i - 1] - Up[i]) + Up[i] - Down[i]);
        dp[i][1] = min(dp[i][1], dp[i - 1][1] + abs(Up[i - 1] - Down[i]) + Up[i] - Down[i]);
        dp[i][1] = min(dp[i][1], dp[i - 1][0] + abs(Down[i - 1] - Down[i]) + Up[i] - Down[i]);
    }
    cout << dp[m][0] + bx - ax << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}