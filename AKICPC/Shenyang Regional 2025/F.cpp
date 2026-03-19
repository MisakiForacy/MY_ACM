#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define siz(x) ((int)x.size())

#define x first
#define y second

using namespace std;
using LL = long long;

const LL inf = 1e15;

void solve()
{
    int n, m, A, B;
    cin >> n >> m >> A >> B;
    vector<vector<LL>> g(n + 1, vector<LL>(n + 1, inf));
    vector<vector<LL>> G(n + 1);
    vector<pair<int, int>> P, p;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u][v] = g[v][u] = 1;
        G[u].push_back(v), G[v].push_back(u);
        P.push_back({u, v});
    }
    if (A == B)
    {
        cout << "No\n";
        return;
    }
    if (g[A][B] != 1)
    {
        cout << "Yes\n";
        for (auto &[u, v] : P)
        {
            if (u == A || u == B)
                swap(u, v);
            cout << u << ' ' << v << '\n';
        }
    }
    else
    {
        vector<LL> path;
        vector<vector<LL>> dis = g;
        vector<vector<LL>> pos(n + 1, vector<LL>(n + 1, 0));
        LL ans = inf;
        auto get = [&](auto get, int u, int v) -> void
        {
            if (pos[u][v] == 0)
                return;
            int k = pos[u][v];
            get(get, u, k);
            path.push_back(k);
            get(get, k, v);
        };
        auto Floyd = [&]()
        {
            for (int k = 1; k <= n; k++)
            {
                for (int i = 1; i < k; i++)
                {
                    for (int j = 1; j < i; j++)
                    {
                        if (ans > (LL)g[i][k] + g[k][j] + dis[i][j])
                        {
                            ans = g[i][k] + g[k][j] + dis[i][j];
                            path.clear();
                            path.push_back(i);
                            path.push_back(k);
                            path.push_back(j);
                            get(get, j, i);
                        }
                    }
                }
                for (int i = 1; i <= n; i++)
                {
                    for (int j = 1; j <= n; j++)
                    {
                        if (dis[i][j] > dis[i][k] + dis[k][j])
                        {
                            dis[i][j] = dis[i][k] + dis[k][j];
                            pos[i][j] = k;
                        }
                    }
                }
            }
        };
        Floyd();
        if (ans == inf)
        {
            cout << "No\n";
        }
        else
        {
            cout << "Yes\n";
            vector<int> use(n + 1, 0), vis(n + 1, 0);
            set<int> pp;
            vector<int> PP, Path(n + 1, 0);
            for (int x : path)
                pp.insert(x), PP.push_back(x);
            int ok = 0;
            vector<pair<int, int>> Ans;
            vector<int> fa(n + 1);
            auto dfs = [&](auto dfs, int u) -> void
            {
                if (pp.count(u))
                    ok = 1;
                if (ok)
                {
                    Path[u] = 1;
                    return;
                }
                for (auto v : G[u])
                {
                    if (!vis[v])
                    {
                        vis[v] = 1;
                        dfs(dfs, v);
                        vis[v] = 0;
                        if (ok)
                            Path[u] = 1;
                    }
                }
            };
            dfs(dfs, A);
            // for (int i = 1;i <= n;i ++) cout << Path[i] << ' ';
            // cout << '\n';
            map<pair<int, int>, int> used;
            int u = A, okk = 1;
            vector<int> visit(n + 1, 0);
            visit[u] = 1;
            // cout << siz(PP) << '\n';
            while (okk)
            {
                okk = 0;
                // cout << u << '\n';
                for (auto v : G[u])
                {
                    if (Path[v] == 1 && !visit[v])
                    {
                        visit[v] = 1;
                        okk = 1;
                        Ans.push_back({u, v});
                        used[{u, v}] = used[{v, u}] = 1;
                        u = v;
                        break;
                    }
                }
            }
            if (!Path[B])
            {
                Path[B] = 1;
                Ans.push_back({B, A});
                used[{A, B}] = used[{B, A}] = 1;
            }
            for (int i = 1; i < siz(PP); i++)
            {
                // cout << PP[i] << '\n';
                Path[PP[i]] = 1;
                Ans.push_back({PP[i - 1], PP[i]});
                used[{PP[i - 1], PP[i]}] = used[{PP[i], PP[i - 1]}] = 1;
            }
            Path[PP[0]] = 1;
            Ans.push_back({PP.back(), PP[0]});
            used[{PP.back(), PP[0]}] = used[{PP[0], PP.back()}] = 1;
            for (auto [x, y] : P)
            {
                if (used.count({x, y}))
                    continue;
                if (Path[x] == 1)
                    swap(x, y);
                cout << x << ' ' << y << '\n';
            }
            for (auto [x, y] : Ans)
            {
                cout << x << ' ' << y << '\n';
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
}

/*
3
5 4 2 4
1 2
2 3
3 4
4 5
5 7 1 2
1 2
2 3
3 4
4 5
1 5
3 5
1 4
2 1 1 2
1 2
*/

/*
1
6 7 1 2
1 2
2 3
3 4
3 5
4 5
4 6
5 6
*/