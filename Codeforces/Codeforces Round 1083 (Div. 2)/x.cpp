#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 1000005;
const int MAXM = 35;
const int MOD = 998244353;

vector<int> adj[MAXN];
int dp[MAXN][MAXM];
int S[MAXN][MAXM];
int n, m, x, y;

void dfs(int u, int p)
{
    // 初始化当前节点在各个亮度下的方案数为 1
    // 因为方案数是子树方案的乘积
    for (int i = 0; i <= m; i++)
    {
        dp[u][i] = 1;
    }

    for (int v : adj[u])
    {
        if (v == p)
        {
            continue;
        }

        dfs(v, u);

        // 转移：当前亮度的方案数等于所有子节点在不大于该亮度时的方案数之积
        for (int i = 0; i <= m; i++)
        {
            long long tmp = dp[u][i];
            tmp = tmp * S[v][i];
            dp[u][i] = tmp % MOD;
        }
    }

    // 计算当前节点的前缀和，供父节点使用
    S[u][0] = dp[u][0];
    for (int i = 1; i <= m; i++)
    {
        S[u][i] = (S[u][i - 1] + dp[u][i]) % MOD;
    }
}

int main()
{
    // 提高 IO 效率
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    if (!(cin >> n >> m))
    {
        return 0;
    }

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cin >> x >> y;

    // 以指定的 x 为根进行 DFS
    dfs(x, 0);

    // 题目要求固定 a_x = y 的方案数
    cout << dp[x][y] << endl;

    return 0;
}