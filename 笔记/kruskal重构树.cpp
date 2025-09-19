/*
* kruskal重构树
* 2025/08/09
* By Foracy 
*
* 原理：图上两点间任意路径最小的最大权
*    = kruskal重构树上两点的最近公共祖先(lca)的点权
* 作用：若单次查询，可用prim求最小生成树(MST)，时间复杂度为O(n)
*    若多次查询，整体O(qn)难以通过，可构建重构树，利用lca求解，单次复杂度为O(logn)
*
* 主要流程：
* 1. 读取图的点数和边数，初始化并查集和重构树结构。
* 2. 按边权升序排序所有边，依次合并不连通的点，构建kruskal重构树。
* 3. 使用DFS预处理每个节点的深度和倍增祖先表，用于后续LCA查询。
* 4. 对每组查询，利用LCA算法求出两点在重构树上的最近公共祖先，并输出该祖先的点权（即原图两点路径的最小最大权）。
*
* 主要变量说明：
* - edge结构体：表示一条边，包含起点u、终点v和权值w。
* - f[]：并查集数组，用于维护连通性。
* - val[]：每个节点的权值，重构树中新节点权值为合并时的边权。
* - g[]：邻接表，存储重构树结构。
* - dep[]：每个节点的深度。
* - fa[][]：倍增祖先表，fa[u][i]表示u的第2^i级祖先。
*
* 关键函数说明：
* - findx：并查集查找带路径压缩。
* - merge：合并两个集合，生成新节点并更新重构树结构。
* - dfs：深度优先遍历，预处理深度和祖先表。
* - lca：倍增法求最近公共祖先。
*
* 时间复杂度：
* - 构建重构树：O(m log n)
* - 单次查询：O(log n)
*/

#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define siz(x) ((int) x.size())
using namespace std;
using LL = long long;

const LL inf = 1e15 + 10;

struct edge
{
    LL u, v, w;
    bool operator < (const edge&that) const {
        return w < that.w;
    }
};

int main(){
    int n, m, cur;
    cin >> n >> m;
    cur = n;
    vector<edge> p;
    vector<vector<LL>> g(n << 1 | 1);
    vector<LL> f(n << 1 | 1, 0), val(n << 1 | 1, inf);
    for (int i = 1;i <= n;i ++) f[i] = i;
    auto findx = [&](auto findx, int x) -> LL {
        if (f[x] != x){
            f[x] = findx(findx, f[x]);
        }
        return f[x];
    };
    auto merge = [&](int u, int v, int w) -> void {
        u = findx(findx, u);
        v = findx(findx, v);
        if (u != v){
            f[u] = f[v] = ++ cur;
            f[cur] = cur;
            val[cur] = w;
            g[cur].push_back(u);
            g[u].push_back(cur);
            g[cur].push_back(v);
            g[v].push_back(cur);
        }
    };
    for (int i = 1;i <= m;i ++){
        int u, v, w;
        cin >> u >> v >> w;
        p.push_back({u, v, w});
    }
    sort(all(p));
    for (int i = 0;i < m;i ++){
        if (findx(findx, p[i].u) != findx(findx, p[i].v)){
            merge(p[i].u, p[i].v, p[i].w);
        }
    }
    vector<LL> dep(n << 1 | 1, 0);
    vector<vector<LL>> fa(n << 1 | 1, vector<LL> (20, 0));
    auto dfs = [&](auto dfs, int pu, int u) -> void {
        dep[u] = dep[pu] + 1;
        fa[u][0] = pu;
        for (int i = 1;i <= 19;i ++){
            fa[u][i] = fa[fa[u][i - 1]][i - 1];
        }
        for (auto v : g[u]){
            if (v == pu) continue;
            dfs(dfs, u, v);
        }
    };
    dfs(dfs, cur, cur);
    auto lca = [&](int u, int v) -> LL {
        if (dep[u] < dep[v]) swap(u, v);  
        for (int i = 19;i >= 0;i --){
            if (dep[fa[u][i]] >= dep[v]){
                u = fa[u][i];
            }
        }
        if (u == v) return u;
        for (int i = 19;i >= 0;i --){
            if (fa[u][i] != fa[v][i]){
                u = fa[u][i];
                v = fa[v][i];
            }   
        }
        return fa[u][0];
    };
    int q;
    cin >> q;
    while (q --){
        int u, v;
        cin >> u >> v;
        cout << val[lca(u, v)] << '\n';
    }
}