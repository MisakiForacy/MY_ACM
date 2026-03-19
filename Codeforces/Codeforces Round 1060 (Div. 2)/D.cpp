#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())
#define lowbit(x) ((x) & (-x))
#define nl cerr << '\n';
#define debug(x) cerr << #x << ':' << x << ' '
#define x first
#define y second
using namespace std;
using LL = long long;
using ULL = unsigned long long;

const int N = 2e5 + 10;
const LL inf = 1e15;
const int P = 131;

mt19937_64 rnd(time(0));

vector<int> p, s(N, 0);
set<int> sp;

void Euler() {
    for (int i = 2;i < N;i ++) {
        if (!s[i]) 
            p.push_back(i);
        for (int j = 0;j < siz(p) && i * p[j] < N;j ++) {
            s[i * p[j]] = 1;
            if (i % p[j] == 0) break;
        }
    }
}

void fxy_ac() {
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1);
    vector<int> d(n + 1, 0);
    vector<int> sz(n + 1, 0), fa(n + 1, 0), vis(n + 1, 0), cnt(n + 1, 0);
    for (int i = 1;i < n;i ++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    auto dfs = [&](auto dfs, int pu, int u) -> void {
        fa[u] = pu;
        d[u] = d[pu] ^ 1;
        for (int v : g[u]) {
            if (v == pu) continue;
            dfs(dfs, u, v);
        }
    };
    dfs(dfs, 0, 1);
    for (int i = 1;i <= n;i ++) cnt[i] = siz(g[i]);
    int cur = 1;
    queue<int> q;
    for (int i = 1;i < n;i ++) {
        if (g[i].size() == 1) {
            q.push(i);
            vis[i] = 1;
        }
    }
    vector<int> ans;
    while (siz(q)) {
        int u = q.front();
        q.pop();
        if (u == n) continue;
        if (d[u] == cur) {
            ans.push_back(-1);
            ans.push_back(u);
            cur ^= 1;
        } else {
            ans.push_back(-1);
            ans.push_back(-1);
            ans.push_back(u);
        }
        for (auto v : g[u]) {
            if (!vis[v]) {
                cnt[v] -= 1;
                if (cnt[v] > 1) continue;
                q.push(v);
                vis[v] = 1;
            }
        }
    }
    cout << siz(ans) << '\n';
    for (int x : ans) {
        if (x == -1)
            cout << 1 << '\n';
        else
            cout << 2 << ' ' << x << '\n';
    }
}

void brute() {

}

int main() {
    // Euler();
    // for (int x : p) sp.insert(x);
    // cout << siz(p) << '\n';
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