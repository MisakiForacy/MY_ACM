#include <bits/stdc++.h>

#define siz(x) ((int)x.size())

#define all(x) begin(x),end(x)

using namespace std;

using LL = long long;

struct node
{
    int a, d, b;
    bool operator < (const node&T) const {
        return d < T.d;
    };
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<node> p(n);
    for (int i = 0;i < n;i ++) cin >> p[i].a >> p[i].d >> p[i].b;
    sort(all(p));
    vector<int> bt(n + 1, 0);
    int cnt = 0;
    for (int i = 0;i < n;i ++) {
        if (!bt[p[i].a]) {
            bt[p[i].a] = 1;
            cnt ++;
        } else bt[p[i].a] ++;
    }
    int idx = 0;
    for (int i = 1;i <= m;i ++) {
        while (idx < n && p[idx].d == i) {
            bt[p[idx].a] --;
            if (bt[p[idx].a] == 0) cnt --;
            bt[p[idx].b] ++;
            if (bt[p[idx].b] == 1) cnt ++;
            idx ++;
        }
        cout << cnt << '\n';
    }
}

int main() {
    // ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}