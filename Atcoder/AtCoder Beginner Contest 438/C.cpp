#include <bits/stdc++.h>

#define x first 
#define y second 

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;
using PLL = pair<LL, LL>;

void solve() {
    int n;
    cin >> n;
    stack<PLL> p;
    for (int i = 1;i <= n;i ++) {
        int x;
        cin >> x;
        if (siz(p) == 0 || p.top().x != x) {
            p.push({x, 1});
        } else {
            p.push({x, p.top().y + 1});
        }
        if (p.top().y == 4) {
            int k = 4;
            while (k --) p.pop();
        }
    }
    cout << siz(p) << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}