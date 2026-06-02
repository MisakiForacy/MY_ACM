#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> pos(n + 1, 0);
    vector<deque<int>> v(n + 1);
    for (int i = 1;i <= n;i ++) {
        pos[i] = i;
        v[i].push_back(i);
    }
    while (q --) {
        int c, p;
        cin >> c >> p;
        
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}