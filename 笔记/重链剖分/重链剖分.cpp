// 重链剖分
#include <bits/stdc++.h>
using namespace std;
using LL = long long;

struct SegTree{
    #define lc p << 1
    #define rc p << 1 | 1
    struct node{
        LL l, r, val;
        node(){l = r = val = 0;}
    };
    vector<node> f;
    vector<LL> a;
    SegTree(int x){f.resize(x << 2 | 3), a.resize(x + 1, 0);}
    void pushup(int p){
        f[p].val = max(f[lc].val, f[rc].val);
    }
    void build(int p, int l, int r){
        f[p].l = l, f[p].r = r;
        if (l == r){
            f[p].val = a[l];
            return;
        }
        int mid = l + r >> 1;
        build(lc, l, mid);
        build(rc, mid + 1, r);
        pushup(p);
    }
    void upd(int p, int id, int val){
        if (f[p].l == f[p].r){
            f[p].val = val;
            return;
        }
        int mid = f[p].l + f[p].r >> 1;
        if (id <= mid) upd(lc, id, val);
        else upd(rc, id, val);
        pushup(p);
    }
    LL qry(int p, int l, int r){
        if (l <= f[p].l && f[p].r <= r) return f[p].val;
        int mid = f[p].l + f[p].r >> 1;
        LL Max = 0;
        if (l <= mid) Max = max(Max, qry(lc, l, r));
        if (r > mid) Max = max(Max, qry(rc, l, r));
        return Max;
    }
};

int main(){
    int n, u, v;
    cin >> n;
    vector<vector<int>> g(n + 1);
    vector<int> a(n + 1, 0);
    for (int i = 1;i <= n - 1;i ++){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1;i <= n;i ++) cin >> a[i];
    /*
    * dfs1
    * 1.先维护每个节点的父节点(fa)
    * 2.维护每个节点的深度(dep)
    * 3.维护每个节点的子树大小(siz)
    * 4.维护每个节点最重的孩子(son)
    */
    vector<int> fa(n + 1, 0), vis(n + 1, 0), dep(n + 1, 0), siz(n + 1, 1), son(n + 1, 0);
    auto dfs1 = [&](auto dfs1, int pu, int u) -> void {
        fa[u] = pu;
        siz[u] = 1;
        dep[u] = dep[pu] + 1;
        int Max = 0;
        for (auto v : g[u]){
            if (v == pu) continue;
            vis[v] = 1;
            dfs1(dfs1, u, v);
            siz[u] += siz[v];
            if (siz[v] > Max){
                Max = siz[v];
                son[u] = v;
            }
        }
    };
    /*
    * dfs2
    * 1.利用重孩子，求重链头节点(top)
    * 2.求dfn序(dfn)
    * 3.求dfn序对应的数值(seg)
    */
    vector<int> top(n + 1, 0), dfn(n + 1, 0), seg(n + 1, 0);
    SegTree f(n);
    f.build(1, 1, n);
    int cur = 0;
    auto dfs2 = [&](auto dfs2, int head, int u) -> void {
        top[u] = head;
        dfn[u] = ++ cur;
        seg[cur] = u;
        f.upd(1, cur, a[u]);
        if (son[u])
            dfs2(dfs2, head, son[u]);
        for (auto v : g[u]){
            if (v == fa[u] || v == son[u]) continue;
            dfs2(dfs2, v, v);
        }
    };
    dfs1(dfs1, 0, 1);
    dfs2(dfs2, 1, 1);
    /**
     * 重剖求LCA
     */
    auto lca = [&](int u, int v) -> LL {
        while (dfn[top[u]] != dfn[top[v]]){
            if (dfn[top[u]] > dfn[top[v]]){
                u = fa[top[u]];
            } else{
                v = fa[top[v]];
            }
        }
        if (dfn[u] > dfn[v]) swap(u, v);
        return u;
    };
    /**
     * 重剖求简单路径最大(点)权
     */
    auto MaxNode = [&](int u, int v) -> LL {
        LL Max = 0;
        while (dfn[top[u]] != dfn[top[v]]){
            if (dfn[top[u]] > dfn[top[v]]){
                Max = max(Max, f.qry(1, dfn[top[u]], dfn[u]));
                u = fa[top[u]];
            } else{
                Max = max(Max, f.qry(1, dfn[top[v]], dfn[v]));
                v = fa[top[v]];
            }
        }
        if (dfn[u] > dfn[v]) swap(u, v);
        Max = max(Max, f.qry(1, dfn[u], dfn[v]));
        return Max;
    };
    // int q;
    // cin >> q;
    // while (q --){
    //     int u, v;
    //     cin >> u >> v;
    //     // cout << MaxNode(u, v) << '\n';
    //     // cout << lca(u, v) << '\n';
    // }
}