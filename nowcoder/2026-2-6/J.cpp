#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;

struct node
{
    LL val, id;
    bool operator < (const node&T) const {
        return val < T.val;
    } 
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<node> v;
    vector<int> alls;
    vector<vector<int>> g(n + 1);
    for (int i = 1;i <= m;i ++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1;i <= n;i ++) alls.push_back(siz(g[u]));
    sort(all(alls));
    alls.erase(unique(all(alls)), alls.end());
    priority_queue<node> que;
    for (int i = 1;i <= n;i ++) {
        v[i].val = lower_bound(all(alls), siz(g[i])) - alls.begin() + 1;
        que.push(v[i]);
    }
    // 4 - 3 - 2 - 1 - 5
    while (siz(que)) {
        auto [val, id] = que.top();
        que.pop();
        
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}