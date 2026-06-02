#include <bits/stdc++.h>

#define x first 
#define y second 

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;

void solve() {
    LL n;
    cin >> n;
    vector<LL> a(n + 1, 0);
    stack<int> stk;
    for (int i = 1;i <= n;i ++) {
        cin >> a[i];
        if (stk.empty()) {
            stk.push(a[i] & 1);
        } else {
            if (stk.top() == (a[i] & 1)) {
                stk.pop();
            } else {
                stk.push(a[i] & 1);
            }
        }
    }
    if (n & 1) {
        cout << (siz(stk) == 1 ? "YES\n" : "NO\n");
    } else {
        cout << (siz(stk) == 0 ? "YES\n" : "NO\n");
    }
}

int main() {
    // cout << (1LL << 14) << '\n';
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}