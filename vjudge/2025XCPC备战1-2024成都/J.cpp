#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())
#define lowbit(x) ((x) & (-x))
#define nl cout << '\n';
#define debug(x) cerr << #x << ':' << x << ' '
#define x first
#define y second
using namespace std;
using LL = long long;

const int N = 2e5 + 10;
const LL inf = 1e15;

mt19937_64 rng(time(0));

void fxy_ac() {
    LL n, m, q;
    cin >> n >> m >> q;
    int cur = 0;
    vector<LL> p(m + 1, 0);
    map<int, int> mp;
    map<pair<int, int>, int> ok;
    for (int i = 1;i <= q;i ++) {
        int opt, idx, x;
        cin >> opt;
        if (opt == 1) {
            cin >> x;
            cur = x;
        } else if (opt == 2) {
            cin >> idx >> x;
            if (x != cur) continue;
            if (ok.count({idx, x})) continue;
            p[idx] += m - mp[x];
            mp[x] ++;
            ok[{idx, x}] = 1;
        } else if (opt == 3) {
            cin >> idx >> x;
            if (x != cur) continue;
            if (ok.count({idx, x})) continue;
            ok[{idx, x}] = 1;
        }
    }
    vector<pair<LL, LL>> ans;
    for (int i = 1;i <= m;i ++) {
        ans.push_back({i, p[i]});
    }
    sort(all(ans), [&](pair<LL, LL> x, pair<LL, LL> y) {
        if (x.y != y.y) return x.y > y.y;
        return x.x < y.x;
    });
    for (auto [x, y] : ans) {
        cout << x << ' ' << y << '\n';
    }
}

void brute() {

}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) {
        fxy_ac();
        // brute();
    }
}