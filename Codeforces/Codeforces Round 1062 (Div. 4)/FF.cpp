#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 2e5 + 10;

int n, k;
vector<int> g[MAXN];

/* 第一次 dfs 的结果 */
int sz[MAXN];          // 以 1 为根时的子树大小
int mxDown[MAXN];      // 以 1 为根时，u 的重儿子（子树最大）的大小

/* 换根时辅助信息 */
int mxUp[MAXN];        // 当根换到 u 时，“父方向”子树的最大 size

/* 答案统计 */
int cnt[MAXN];         // cnt[s] : 有多少个根 r 使得 subtree_r(u) == s
ll ans = 0;            // 最终 kawaiiness

/* ---------- 第一次 dfs：计算 sz 和 mxDown ---------- */
void dfs1(int u, int fa) {
    sz[u] = 1;
    mxDown[u] = 0;
    for (int v : g[u]) if (v != fa) {
        dfs1(v, u);
        sz[u] += sz[v];
        mxDown[u] = max(mxDown[u], sz[v]);
    }
}

/* ---------- 第二次 dfs：换根，同时统计答案 ---------- */
void dfs2(int u, int fa, int upSize) {
    /* 1. 计算当前根为 u 时，u 的“子树大小”就是 n，最大子树是 max(mxDown[u], upSize) */
    int total = n;
    int maxPart = max(mxDown[u], upSize);

    /* 2. 判断 u 是否对当前根 u 有贡献 */
    if (total >= k && (total - maxPart) >= 1)
        ans += 1;

    /* 3. 为儿子准备新的 upSize，并继续换根 */
    /* 先收集所有儿子的 sz，用于计算“次大”信息 */
    vector<int> sons;
    for (int v : g[u]) if (v != fa) sons.push_back(sz[v]);
    sons.push_back(upSize);          // 父方向也当成一个“虚拟儿子”
    sort(sons.rbegin(), sons.rend()); // 从大到小

    for (int v : g[u]) if (v != fa) {
        int newUp;
        /* 如果 v 是最大子树，则次大子树成为新的 maxUp */
        if (sz[v] == sons[0])
            newUp = (sons.size() >= 2 ? sons[1] : 0) + (n - sz[v]);
        else
            newUp = sons[0] + (n - sz[v]);

        dfs2(v, u, newUp);
    }
}

/* ---------- 主函数 ---------- */
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs1(1, 0);
    dfs2(1, 0, 0);

    cout << ans << '\n';
    return 0;
}