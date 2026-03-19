#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

#define x first 
#define y second 

using namespace std;
using LL = long long;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<char>> Mp(n + 1, vector<char> (m + 1, 0));
    vector<vector<vector<int>>> Pre(4, vector<vector<int>>(n + 1, vector<int>(m + 1, 0)));
    auto get = [&](char c) -> int {
        if (c == 'B') return 1;
        if (c == 'G') return 2;
        if (c == 'P') return 3;
    }; 
    for (int i = 1;i <= n;i ++) {
        for (int j = 1;j <= m;j ++) {
            char c;
            cin >> c;
            Mp[i][j] = c;
            Pre[get(c)][i][j] = 1;
        }
    }
    for (int t = 1;t <= 3;t ++) {
        for (int i = 1;i <= n;i ++) {
            for (int j = 1;j <= m;j ++) {
                Pre[t][i][j] += Pre[t][i - 1][j] + Pre[t][i][j - 1] - Pre[t][i - 1][j - 1];        
            }
        }
    }
    int Ans = 0;
    int Up = 0;
    int U, D, L, R;
    char C;
    U = D = L = R = 0;
    auto cal = [&](int C, int Up, int Down, int l, int r) -> LL {
        return Pre[C][Down][r] - Pre[C][Down][l] - Pre[C][Up][r] + Pre[C][Up][l];
    };
    auto check = [&](int Up, int Down, int l, int r) -> int {
        int ok = 0;
        int S = (Down - Up) * (r - l);
        int B = cal(1, Up, Down, l, r);
        int G = cal(2, Up, Down, l, r);
        int P = cal(3, Up, Down, l, r);
        if (P == S || (B + G == S && min(B, G) <= k)) {
            ok = 1;
            if (Ans < S) {
                Ans = S;
                if (P == S) C = 'P';
                if (B + G == S && B <= k) C = 'G';
                if (B + G == S && G <= k) C = 'B';
                U = Up + 1, D = Down, L = l + 1, R = r;
            }
        }
        return ok;
    };
    for (int Down = 1;Down <= n;Down ++) {
        for (int Up = 0;Up < Down;Up ++) {
            int l = 0;
            for (int r = 1;r <= m;r ++) {
                while (!check(Up, Down, l, r) && l < r) l ++;
            }
        }
    }
    cout << Ans << '\n';
    // cout << U << ' ' << D << ' ' << L << ' ' << R << '\n';
    for (int i = U;i <= D;i ++) {
        for (int j = L;j <= R;j ++) {
            Mp[i][j] = C;
        }
    }
    for (int i = 1;i <= n;i ++) {
        for (int j = 1;j <= m;j ++) {
            cout << Mp[i][j];
        }
        cout << '\n';
    }
}
// 5 4 4 3 3 2 2 1 1
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}