#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;

struct node
{
    LL v, id, ans;
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> Mp(n + 1, vector<char> (m + 1));
    int _0 = 0, _1 = 0;
    for (int i = 1;i <= n;i ++) {
        for (int j = 1;j <= m;j ++) {
            cin >> Mp[i][j];
            if (Mp[i][j] == '0') _0 ++;
            if (Mp[i][j] == '1') _1 ++;
        }
    }
    for (int i = 1;i <= n;i ++) {
        for (int j = 1;j <= m;j ++) {
            if ((_0 == 1 && Mp[i][j] == '0') || (_1 == 1 && Mp[i][j] == '1')) {
                cout << "N";
            } else {
                cout << "Y";
            }
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}