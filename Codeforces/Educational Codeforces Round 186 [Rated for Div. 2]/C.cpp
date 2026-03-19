#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

#define x first 
#define y second 

using namespace std;
using LL = long long;

void solve() {
    int n;
    cin >> n;
    vector<LL> a(n + 1), b(n + 1), c(n + 1);
    for (int i = 1;i <= n;i ++) cin >> a[i];
    for (int i = 1;i <= n;i ++) cin >> b[i];
    for (int i = 1;i <= n;i ++) cin >> c[i];
    LL A = 0, B = 0;
    deque<int> aa, bb, cc;
    for (int i = 1;i <= n;i ++) aa.push_back(a[i]);
    for (int i = 1;i <= n;i ++) bb.push_back(b[i]);
    for (int i = 1;i <= n;i ++) cc.push_back(c[i]);
    for (int j = 1;j <= n;j ++) {
        int x = bb.front();
        bb.pop_front(), bb.push_back(x);
        int okA = 1, okB = 1;
        for (int i = 0;i < n;i ++) {
            if (bb[i] <= aa[i]) okA = 0;
            if (cc[i] <= bb[i]) okB = 0;
        }
        A += okA, B += okB;
    }
    LL Ans = A * B * n;
    cout << Ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}