#include <bits/stdc++.h>

#define x first 
#define y second 

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;

void solve() {
    LL k;
    cin >> k;
    string s = "codeforces";
    vector<int> use(10, 1);
    LL cur = 1, idx = 0;
    while (cur < k) {
        cur /= use[idx];
        use[idx] ++;
        cur *= use[idx];
        idx = (idx + 1) % 10;
    }
    for (int i = 0;i < 10;i ++) {
        for (int j = 0;j < use[i];j ++) {
            cout << s[i];
        }
    }
    cout << '\n';
}

int main() {
    // cout << (1LL << 14) << '\n';
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}