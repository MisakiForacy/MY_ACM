#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

#define x first 
#define y second 

using namespace std;
using LL = long long;

void solve() {
    int h, w, n;
    cin >> h >> w >> n;
    vector<vector<int>> Mp(h + 1, vector<int> (w + 1, 0));
    for (int i = 1;i <= h;i ++) {
        for (int j = 1;j <= w;j ++) {
            cin >> Mp[i][j];
        }
    }
    map<int, int> use;
    for (int i = 1;i <= n;i ++) {
        int x; cin >> x;
        use[x] = 1;
    }
    int Mx = 0;
    for (int i = 1;i <= h;i ++) {
        int cnt = 0;
        for (int j = 1;j <= w;j ++) {
            if (use.count(Mp[i][j])) 
                cnt ++;
        }
        Mx = max(Mx, cnt);
    }
    cout << Mx << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}