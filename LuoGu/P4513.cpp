#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 5e5 + 10, inf = 1e18;

struct node{
    int mx, lmx, rmx, sum;
    node(int x = inf){
        mx = lmx = rmx = sum = x;
    }

    node friend operator + (node a, node b){
        if (a.mx == inf)
            return b;
        if (b.mx == inf)
            return a;
        node ans;
        ans.mx = max({a.mx, b.mx, a.rmx + b.lmx});
        ans.lmx = max(a.lmx, a.sum + b.lmx);
        ans.rmx = max(b.rmx, b.sum + a.rmx);
        ans.sum = a.sum + b.sum;
        return ans;
    }
} tr[N * 4];
int n, m, a[N];
#define lu u << 1
#define ru u << 1 | 1
#define mid ((l + r) >> 1)
#define lson lu, l, mid
#define rson ru, mid + 1, r
#define root 1, 1, n

void push_up(int u){
    tr[u] = tr[lu] + tr[ru];
}
void build(int u, int l, int r){
    if (l == r){
        tr[u] = node(a[l]);
        return;
    }
    build(lson), build(rson);
    push_up(u);
}

void change(int u, int l, int r, int L, int R, int k){
    if (l == L && r == R){
        tr[u] = node(k);
        return;
    }
    if (L <= mid)
        change(lson, L, min(R, mid), k);
    if (R > mid)
        change(rson, max(L, mid + 1), R, k);
    push_up(u);
}

node query(int u, int l, int r, int L, int R){
    if (l == L && r == R){
        return tr[u];
    }
    node res = node();
    if (L <= mid)
        res = res + query(lson, L, min(R, mid));
    if (R > mid)
        res = res + query(rson, max(L, mid + 1), R);
    return res;
}

signed main(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    build(root);
    for (int i = 1; i <= m; i++){
        int op, l, r, x, k;
        cin >> op;
        if (op == 1){
            cin >> l >> r;
            if (l > r)
                swap(l, r);
            cout << query(root, l, r).mx << '\n';
        }
        else{
            cin >> x >> k;
            change(root, x, x, k);
        }
    }
}
