#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

#define x first 
#define y second 

#define LOG 60

using namespace std;
using LL = long long;

const LL MOD = 1e9 + 7;

const LL dx[] = {0, 1, 0, -1};
const LL dy[] = {1, 0, -1, 0};

const LL N = 1e4 + 10;

vector<int> P, S(N, 0);

void Euler() {
    S[1] = 1;
    P.push_back(0);
    for (int i = 2;i < N;i ++) {
        if (!S[i]) P.push_back(i), S[i] = i;
        for (int j = 1;j < siz(P) && P[j] * i < N;j ++) {
            S[P[j] * i] = max(S[j], S[i]);
            if (i % P[j] == 0) break;
        }
    }
}

vector<int> p = {0}, pre(31, 0);

// 5 4 3

void solve() {
    int n;
    scanf("%d", &n);
    vector<int> a(2 * n);
    for (int i = 0;i < n;i ++) scanf("%d", &a[i]), a[i + n] = a[i];
    int mx = 0; // 
    auto cal = [&]() -> void {
        vector<vector<int>> dp(2 * n + 1, vector<int> (11, 2 * n + 1));
        for (int j = 1;j <= 10;j ++) {
            for (int i = 2 * n - 1;i >= 0;i --) {
                dp[i][j] = (a[i] >= j ? i : dp[i + 1][j]);
            }
        }
        for (int i = 0;i < n;i ++) {
            int cur = i;
            int idx = 0;
            int res = 0;
            while (cur - i < n) {
                while (a[cur] >= P[idx] - res) idx ++;
                res = P[idx - 1];
                if (P[idx] - res > 10) break;
                cur = dp[cur + 1][P[idx] - res];
            }
            mx = max(mx, res);
        }
    };
    cal();
    reverse(all(a));
    cal();
    printf("%d\n", mx);
}

// 127-113=14 

// max = 113

int main() {
    Euler();
    for (int i = 1;i <= siz(P);i ++) {
        if (P[i] - P[i - 1] > 10) {
            break;
        } else {
            p.push_back(P[i] - P[i - 1]);
        }
    }
    for (int i = 1;i < 30;i ++) pre[i] = pre[i - 1] + p[i];
    // for (int x : p) cout << x << '\n';
    // cout << siz(p) << '\n';
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    scanf("%d", &T);
    while (T --) solve();
}