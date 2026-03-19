#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

#define x first 
#define y second 

using namespace std;
using LL = long long;

struct node
{
    LL W, P;
};

void solve() {
    int n;
    cin >> n;
    vector<node> v(n + 1);
    for (int i = 1;i <= n;i ++) cin >> v[i].W >> v[i].P;
    sort(v.begin() + 1, v.end(), [&](node x, node y) {
        return x.W + x.P < y.W + y.P;
    });
    vector<LL> pre(n + 1, 0), suf(n + 2, 0);
    for (int i = 1;i <= n;i ++) pre[i] = pre[i - 1] + v[i].W;
    for (int i = n;i >= 1;i --) suf[i] = suf[i + 1] + v[i].P;
    int Mx = 0;
    for (int i = 1;i <= n;i ++) {
        if (suf[i + 1] >= pre[i]) Mx = max(Mx, i);
    }
    cout << Mx << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}