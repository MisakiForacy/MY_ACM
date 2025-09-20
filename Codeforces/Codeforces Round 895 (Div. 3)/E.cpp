#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define debug(x) cerr << #x << ':' << x << ' '
using namespace std;
using LL = long long;
const LL inf = LLONG_MAX;

LL g,g0,g1;

struct SegmentTree{
    #define lc p << 1
    #define rc p << 1 | 1
    #define mid(l,r) (l + r >> 1)
    struct node{
        int l,r,val,f,x0,x1;
        node(int x = 0){
            l = r = f = x0 = x1 = x;
        }
        node friend operator+(node a,node b){
            node res;
            res.x0 = a.x0 ^ b.x0;
            res.x1 = a.x1 ^ b.x1;
            res.l = min(a.l,b.l);
            res.r = max(a.r,b.r);
            return res;
        }
    };
    vector<node> tr;
    vector<int> a,b;
    SegmentTree(int n){
        tr.resize(4*n+4);
        a.resize(n+1);
        b.resize(n+1);
    }
    void pushdown(int p){
        if (tr[p].f){
            tr[lc].f = !tr[lc].f;
            tr[rc].f = !tr[rc].f;
            swap(tr[lc].x0, tr[lc].x1);
            swap(tr[rc].x0, tr[rc].x1);
        }   
    }
    void build(int p,int l,int r){
        tr[p].l = l, tr[p].r = r;
        if (l == r){
            tr[p].x1 = b[l] * a[l];
            tr[p].x0 = (!b[l]) * a[l];
            return;
        }
        build(lc,l,mid(l,r));
        build(rc,mid(l,r)+1,r);
        tr[p] = tr[lc] + tr[rc];
    }
    void update(int p,int l,int r){
        if (l <= tr[p].l && tr[p].r <= r){
            tr[p].f = !tr[p].f;
            g0 = g0 ^ tr[p].x0 ^ tr[p].x1;
            g1 = g1 ^ tr[p].x0 ^ tr[p].x1;
            swap(tr[p].x0, tr[p].x1);
            return;
        }
        pushdown(p);
        int mid = mid(tr[p].l,tr[p].r);
        if (l <= mid) update(lc,l,min(mid,r));
        if (r > mid) update(rc,max(l,mid+1),r);
        tr[p] = tr[lc] + tr[rc];
    }
    node query(int p,int l,int r){
        if (l <= tr[p].l && tr[p].r <= r) return tr[p];
        pushdown(p);
        int mid = mid(tr[p].l,tr[p].r);
        node res;
        if (l <= mid) res = res + query(lc,l,min(mid,r));
        if (r > mid) res = res + query(rc,max(l,mid+1),r);
        return res;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --){
        g = g0 = g1 = 0;
        int n; cin >> n;
        SegmentTree tr(n);
        for (int i = 1;i <= n;i ++) cin >> tr.a[i], g ^= tr.a[i];
        for (int i = 1;i <= n;i ++){
            char c;
            cin >> c;
            tr.b[i] = c == '1';
            if (c == '1'){
                g1 ^= tr.a[i];
            }
        }
        g0 = g ^ g1;
        tr.build(1, 1, n);
        int q; cin >> q;
        while (q --){
            int op, l, r; cin >> op;
            if (op == 1){
                cin >> l >> r;
                tr.update(1, l, r);
            } else{
                cin >> l;
                if (l == 1){
                    cout << g1 << ' ';
                } else{
                    cout << g0 << ' ';
                }
            }
        }
        cout << '\n';
    }
}