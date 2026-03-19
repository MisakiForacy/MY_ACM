#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;

struct node
{
    int u, v, w;
};

void solve() {
    LL n, m, k;
    cin >> n >> m >> k;
    if (n == 1) {
        if (k == 0) cout << "YES\n";
        else        cout << "NO\n";
        return;
    }
    LL Mi = n * (n - 1) / 2;
    if (Mi > k) {
        cout << "NO\n";
        return;
    }
    LL S = Mi;
    vector<int> use;
    for (int i = 1;i <= n - 1;i ++) use.push_back(i);
    LL p = n - 2, V = m;
    while (S < k && p >= 0) {
        LL need = k - S;
        if (need >= V - use[p]) {
            LL add = V - use[p];
            S += add;
            need -= add;
            use[p] += add;
            V --, p --;
        } else {
            S += need;
            use[p] += need;
        }
    }
    if (p < 0) {
        cout << "NO\n";
        return;
    }
    vector<node> ans;
    set<LL> nums;
    for (int x : use) nums.insert(x);
    int u = 0, v = 1, px = 3;
    vector<int> lst(m + 1, 0);
    for (int i = 1;i <= m;i ++) lst[i] = i - 2;
    for (int i = 1;i <= m;i ++) {
        if (nums.count(i)) {
            u ++, v ++;
            ans.push_back({u, v, i});
        } else {
            if (px > v) {
                cout << "NO\n";
                return;
            }
            if (lst[px]) {
                ans.push_back({px, lst[px], i});
                lst[px] --;
                if (lst[px] == 0) px ++;
            }
        }
    }
    cout << "YES\n";
    for (auto [x, y, d] : ans) cout << x << ' ' << y << ' ' << d << '\n';
}

// 1 2 3 4

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}