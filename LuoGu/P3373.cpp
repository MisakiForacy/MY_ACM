#include <bits/stdc++.h>
#define lc p<<1
#define rc p<<1|1
using namespace std;
using LL = long long;
const int N = 1e5+10;
struct node{
    LL l,r,v,add,mul;
};
vector<node> tr;
vector<LL> a;
void pushup(int p){
    tr[p].v = tr[lc].v + tr[rc].v;
}
void pushdown(int p){
    tr[lc].v += tr[p].add*(tr[lc].r-tr[lc].l+1);
    tr[rc].v += tr[p].add*(tr[rc].r-tr[rc].l+1);
    tr[rc].add += tr[p].add;
    tr[lc].add += tr[p].add;
    tr[p].add = 0;
}
void update(int p,int x,int y,int k){
    if (x<=tr[p].l && tr[p].r<=y){
        tr[p].v += (tr[p].r-tr[p].l+1) * k;
        tr[p].add += k;
        return;
    }
    int m = (tr[p].l+tr[p].r) >> 1;
    pushdown(p);
    if (x <= m) update(lc,x,y,k);
    if (y > m) update(rc,x,y,k);
    pushup(p);
}
ll query(int p,int x,int y){
    if (x<=tr[p].l && tr[p].r<=y){
        return tr[p].v;
    }
    int m = (tr[p].l+tr[p].r) >> 1;
    pushdown(p);
    ll sum = 0;
    if (x <= m) sum += query(lc,x,y);
    if (y > m) sum += query(rc,x,y);
    return sum;
}
void build(int p,int l,int r){
    tr[p] = {l,r,a[l],0,0};
    if (l == r) return;
    int m = l + r >> 1;
    build(lc,l,m);
    build(rc,m+1,r);
    pushup(p);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n,q,m;
    cin >> n >> q >> m;
    tr.resize(4*n);
    a.resize(n+1,0);
    for (int i=1;i<=n;i++) cin >> a[i];
    build(1,1,n);
    for (int i=0;i<q;i++){
        int op,l,r,k;
        cin >> op;
        if (op == 1){
            cin >> l >> r >> k;
            update(l,r,k);
        } else if (op == 2){
            cin >> l >> r >> k;
            update(l,r,k);
        } else{
            cin >> l >> r;
            cout << query(1,l,r) << '\n';
        }
    }
}