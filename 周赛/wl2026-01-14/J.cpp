#include <bits/stdc++.h>

#define x first 
#define y second 

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;
using PII = pair<LL, LL>;

void solve() {
    int n, Mx = 0, Tp;
    cin >> n;
    map<int, int> mp;
    vector<LL> a(n + 2, 0);
    for (int i = 1;i <= n;i ++) cin >> a[i], mp[a[i]] ++;
    for (auto [k, v] : mp) {
        if (v > Mx) {
            Mx = v;
            Tp = k;
        }
    }
    a[0] = a[n + 1] = Tp;
    if (n == 1) {
        cout << 0 << '\n';
        return;
    }
    queue<int> q;
    for (int i = 1;i <= n;i ++) {
        if (a[i] == Tp && (a[i - 1] != Tp || a[i + 1] != Tp)) {
            q.push(i);
        }
    }
    struct node {int x, y, z;};
    vector<node> Ans;
    while (siz(q)) {
        int u = q.front();
        q.pop();
        if (a[u - 1] < a[u]) {
            Ans.push_back({1, u - 1, u});
            q.push(u - 1);
        } else if (a[u - 1] > a[u]) {
            Ans.push_back({2, u - 1, u});
            q.push(u - 1);
        }
        if (a[u + 1] < a[u]) {
            Ans.push_back({1, u + 1, u});
            q.push(u + 1);
        } else if (a[u + 1] > a[u]) {
            Ans.push_back({2, u + 1, u});
            q.push(u + 1);
        }
        a[u - 1] = a[u], a[u + 1] = a[u];
    }
    cout << siz(Ans) << '\n';
    for (auto [x, y, z] : Ans) {
        cout << x << ' ' << y << ' ' << z << '\n';
    }
}

int main() {
    // ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}