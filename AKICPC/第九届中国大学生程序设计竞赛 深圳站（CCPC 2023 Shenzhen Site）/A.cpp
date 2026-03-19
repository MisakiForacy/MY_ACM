#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())
using namespace std;
using LL = long long;

void solve() {
    LL n;
    cin >> n;
    vector<int> a(n, 0), b(n + 1, 0), V(n);
    map<int, vector<int>> mp;
    for (int i = 1;i <= n;i ++) cin >> b[i];
    for (int i = 1;i <= n;i ++) {
        mp[b[i]].push_back(i);
    }
    vector<pair<int, int>> p(n);
    for (int i = 1;i <= n;i ++) {
        p[i - 1].first = b[i];
        p[i - 1].second = i;
    }
    sort(all(p));
    for (int i = 1;i <= n;i ++) V[i - 1] = p[i - 1].first;
    vector<pair<int, int>> ans;
    auto dfs = [&](auto dfs, int l, int r) -> void {
        if (l + 1 == r) return;
        int mid = l + r >> 1;
        // cout << mid << ' ' << l << ' ' << r << " : \n";
        if (a[mid] < V[mid]) {
            for (int j = mid;j < r;j ++) {
                ans.push_back({2, p[j].second});
                a[j] ++;
            }
        }
        vector<int> pp(n + 1, 0);
        while (a[mid] + pp[mid] < V[mid]) {
            ans.push_back({1, a[mid] + pp[mid]});
            pp[mid] ++, pp[r] --;
        }
        // if (a[l] < V[l]) {
        //     for (int j = l;j < mid;j ++) {
        //         ans.push_back({1, p[j].second});
        //         a[j] ++;
        //     }
        // }
        while (a[l] + pp[l] < V[l]) {
            ans.push_back({1, a[l] + pp[l]});
            pp[l] ++, pp[mid] --;
        }
        a[0] += pp[0]; 
        for (int i = 1;i < n;i ++) {
            // cout << pp[i] << ' ';
            pp[i] += pp[i - 1];
            a[i] += pp[i];
        }
        // cout << '\n';
        dfs(dfs, mid, r);
        dfs(dfs, l, mid);
    };
    dfs(dfs, 0, n);
    cout << siz(ans) << '\n';
    for (auto [x, y] : ans) {
        cout << x << ' ' << y << '\n';
    }
}

/*
4
2 4 3 1
*/

int main() {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    // cout << 1000 << '\n';
    // for (int i = 0;i < 1000;i ++) cout << i << ' ';
    // cout << '\n';
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}