#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve () {
    int n;
    cin >> n;
    vector<vector<LL>> Map(2002, vector<LL> (2002, 0));
    vector<vector<LL>> Cnt(2002, vector<LL> (2002, 0));
    vector<int> u(n + 1), d(n + 1), l(n + 1), r(n + 1);
    for (int i = 1;i <= n;i ++) {
        cin >> u[i] >> d[i] >> l[i] >> r[i];
        Map[u[i]][l[i]] ++, Map[u[i]][r[i] + 1] --;
        Map[d[i] + 1][l[i]] --, Map[d[i] + 1][r[i] + 1] ++;
    }
    for (int i = 1;i <= 2000;i ++) {
        for (int j = 1;j <= 2000;j ++) {
            Map[i][j] += Map[i - 1][j] + Map[i][j - 1] - Map[i - 1][j - 1];
        }
    }
    for (int i = 1;i <= 2000;i ++) {
        for (int j = 1;j <= 2000;j ++) {
            Cnt[i][j] += Map[i][j] == 1;
        }
    }
    for (int i = 1;i <= 2000;i ++) {
        for (int j = 1;j <= 2000;j ++) {
            Cnt[i][j] += Cnt[i - 1][j] + Cnt[i][j - 1] - Cnt[i - 1][j - 1];
        }
    }
    LL Ans = 0;
    for (int i = 1;i <= 2000;i ++) {
        for (int j = 1;j <= 2000;j ++) {
            Ans += (Map[i][j] == 0);
        }
    }
    for (int i = 1;i <= n;i ++) {
        LL Dat = Cnt[d[i]][r[i]] - Cnt[u[i] - 1][r[i]] - Cnt[d[i]][l[i] - 1] + Cnt[u[i] - 1][l[i] - 1];
        cout << Ans + Dat << '\n';
    }
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve ();
}