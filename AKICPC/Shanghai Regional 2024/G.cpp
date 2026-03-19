#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())
#define lowbit(x) ((x) & (-x))
#define x first 
#define y second 
using namespace std;
using LL = long long;

const LL MOD = 998244353;

struct node
{
    LL a, b;
};

void solve() {
    int n;
    cin >> n;
    vector<node> p(n), p1, p2;
    vector<int> c(n);
    for (int i = 0;i < n;i ++) cin >> p[i].a;
    for (int i = 0;i < n;i ++) cin >> p[i].b;
    for (int i = 0;i < n;i ++) cin >> c[i];
    for (int i = 0;i < n;i ++) {
        if (p[i].a >= 0) p1.push_back(p[i]);
        if (p[i].a  < 0) p2.push_back(p[i]);
    }
    sort(all(p1), [&](node x, node y) {
        if (x.a != x.b) return x.a < y.a;
        return x.b < y.b;
    });
    sort(all(p2), [&](node x, node y) {
        if (x.a != x.b) return x.a > y.a;
        return x.b < y.b;
    });
    sort(all(c));
    LL lo = 1, hi = 1e18;
    auto check = [&](LL val) -> int {
        LL cnt = 0;
        for (int j = 0;j < n;j ++) {
            if (p[j].a == 0) 
                cnt += (p[j].b >= val);
            if (p[j].a < 0) {
                
            }
        }
        return cnt >= n / 2;
    };
    while (lo < hi) {
        LL mid = lo + hi >> 1;
        if (check(mid)) lo = mid + 1;
        else hi = mid - 1;
    }
    if (!check(lo)) lo --;
    cout << lo << '\n';
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}