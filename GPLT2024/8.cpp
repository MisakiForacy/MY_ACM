#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;

void solve() {
    int ok = 1;
    vector<vector<int>> a(10, vector<int>(10));
    for (int i = 1;i <= 9;i ++) {
        for (int j = 1;j <= 9;j ++) {
            cin >> a[i][j];
            if (a[i][j] < 1 || a[i][j] > 9) ok = 0;
        }
    }
    if (!ok) {
        cout << 0 << '\n';
        return;
    }
    for (int i = 1;i <= 9;i ++) {
        vector<int> use(10, 0);
        for (int j = 1;j <= 9;j ++) {
            use[a[i][j]] ++;
            if (use[a[i][j]] != 1) ok = 0;
        }
    }
    for (int j = 1;j <= 9;j ++) {
        vector<int> use(10, 0);
        for (int i = 1;i <= 9;i ++) {
            use[a[i][j]] ++;
            if (use[a[i][j]] != 1) ok = 0;    
        }
    }
    for (int i = 1;i <= 9;i += 3) {
        for (int j = 1;j <= 9;j += 3) {
            vector<int> use(10, 0);
            for (int ii = i;ii < i + 3;ii ++) {
                for (int jj = j;jj < j + 3;jj ++) {
                    use[a[ii][jj]] ++;
                    if (use[a[ii][jj]] != 1) ok = 0;
                }
            }
        }
    }
    cout << ok << '\n';
}

int main() {
    cout << fixed << setprecision(2);
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}