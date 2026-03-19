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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mp(n + 1, vector<int> (m + 1));
    vector<vector<int>> ans(n + 2, vector<int> (m + 2, n * m + 2));
    for (int i = 1;i <= n;i ++) {
        for (int j = 1;j <= m;j ++) {
            char c;
            cin >> c;
            mp[i][j] = c == '1';
        }
    }
    if (m <= n) {
        for (int i = 1;i <= m;i ++) {
            for (int j = i + 1;j <= m;j ++) {
                int lst = 0;
                for (int k = 1;k <= n;k ++) {
                    if (mp[k][i] && mp[k][j]) {
                        if (lst == 0) lst = k;
                        else
                        {
                            int v = (k - lst + 1) * (j - i + 1);
                            for (int jj = lst;jj <= k;jj ++) ans[jj][j] = min(ans[jj][j], v);
                            lst = k;
                        }
                    }
                }
            }
            for (int j = m;j >= i;j --)
                for (int k = 1;k <= n;k ++)
                    ans[k][j] = min(ans[k][j], ans[k][j + 1]);
        }
    } else {
        for (int i = 1;i <= n;i ++) {
            for (int j = i + 1;j <= n;j ++) {
                int lst = 0;
                for (int k = 1;k <= m;k ++) {
                    if (mp[i][k] && mp[j][k]) {
                        if (lst == 0) lst = k;
                        else
                        {
                            int v = (k - lst + 1) * (j - i + 1);
                            for (int jj = lst;jj <= k;jj ++) ans[j][jj] = min(ans[j][jj], v);
                            lst = k;
                        }
                    }
                }
            }
            for (int j = n;j >= i;j --) 
                for (int k = 1;k <= m;k ++)
                    ans[j][k] = min(ans[j][k], ans[j + 1][k]);
        }
    }
    for (int i = 1;i <= n;i ++) {
        for (int j = 1;j <= m;j ++) {
            if (ans[i][j] != n * m + 2)
                cout << ans[i][j] << ' ';
            else
                cout << 0 << ' ';
        }
        cout << '\n';    
    }
}

void brute() {

}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) {
        fxy_ac();
        // brute();
    }
}