#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;

using LL = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> w(n + 1);
    stack<int> stk;
    int ans = 0;
    for (int i = 1;i <= n;i ++) {
        cin >> w[i];
        if (w[i] == 0) ans ++;
        else {
            if (siz(stk) && w[i] != stk.top()) {
                stk.pop();
                ans ++;
            } else {
                stk.push(w[i]);
            }
        }
    }
    ans += siz(stk) / 3;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}