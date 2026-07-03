#include <bits/stdc++.h>

#define all(x) begin(x),end(x)

#define siz(x) ((int)x.size())

using namespace std;

using LL = long long;

const double inf = 1e18;

struct node
{
    double d, p;
    bool operator < (const node&T) const {
        return d > T.d;
    }
};

void solve() {
    double s, c, l, p;
    int n;
    cin >> s >> c >> l >> p >> n;
    vector<node> a(n + 2);
    a[0] = {0, p};
    a[n + 1] = {s, inf};
    for (int i = 1;i <= n;i ++) cin >> a[i].d >> a[i].p;
    
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}
