#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

#define x first 
#define y second 

using namespace std;
using LL = long long;

const int N = 2e5;
const LL inf = 1e15;

void solve() {
    int n, k;
    cin >> n >> k;
    string s, t;
    cin >> s >> t;
    s = ' ' + s, t = ' ' + t;
    if (s[1] != t[1]) {
        cout << -1 << '\n';
        return;
    }
    int kk = 0;
    vector<int> pos(26, 0), p(n + 1, 0), use(n + 1, 0);
    p[1] = k + 1;
    for (int i = 1;i <= n;i ++) {
        pos[s[i] - 'a'] = i;
        if (pos[t[i] - 'a'] == 0) {
            cout << -1 << '\n';
            return;
        }
        p[i] = i - pos[t[i] - 'a'];
        if (p[i]) use[pos[t[i] - 'a']] = i;
        // if ((p[i] > p[i - 1] && p[i - 1]) || ) {
        //     cout << -1 << '\n';
        //     return;
        // }
        kk = max(kk, p[i]);
    }
    for (int i = 1;i <= n;i ++) cout << p[i] << ' ';
    cout << '\n';
    for (int i = 1;i <= n;i ++) cout << use[i] << ' ';
    cout << '\n';
    LL ans = (kk > k ? -1 : kk);
    cout << ans << '\n';
    string lst = s, cur;
    for (int i = 1;i <= ans;i ++) {
        cur = lst;
        for (int j = 2;j <= n;j ++) {
            if (lst[j] != t[j] || use[j - 1] != j - 1) {
                cur[j] = lst[j - 1];
                use[j] = use[j - 1];
                use[j - 1] = 0;
                // if (use[j] == j) use[j] = 0;
            } 
        }
        lst = cur;
        cout << lst.substr(1, n) << '\n';
    }
}

int main () {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve ();
}