#include <bits/stdc++.h>
#define lc p<<1
#define rc p<<1|1
using namespace std;
typedef long long ll;
const int N = 2e5+10;
struct node{
    ll l,r,v,lazy;
    node(int x = -1){
        lazy = x;
    }
    node friend operator + (node a,node b){
        node res;
        
        return res;
    }
}b[N];
vector<node> tr;
vector<ll> a;
void pushup(int p){
    tr[p] = tr[lc] + tr[rc];
}
void upd(int u,int len,int k){
    tr[u].v += len * k;
    tr[u].lazy += k;
}
void pushdown(int p){
    if (tr[p].lazy){
        upd(lc,tr[lc].r - tr[lc].l + 1, tr[p].lazy);
        upd(rc,tr[rc].r - tr[rc].l + 1, tr[p].lazy);
        tr[p].lazy = 0; 
    }
}
void build(int p,int l,int r){
    tr[p] = {l,r,a[l],0};
    if (l==r) return;
    int m = (l+r) >> 1;
    build(lc,l,m);
    build(rc,m+1,r);
    pushup(p);
}
void update(int p,int x,int y,int k){
    if (x<=tr[p].l && tr[p].r<=y){
        upd(p,tr[p].r - tr[p].l + 1, k);
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
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n,m;
    cin >> n >> m;
    tr.resize(n*4);
    a.resize(n+1,0);
    for (int i=1;i<=n;i++){
        cin >> a[i];
    }
    build(1,1,n);
    for (int i=0;i<m;i++){
        int op,x,y,k;
        cin >> op;
        if (op==1){
            cin >> x >> y >> k;
            update(1,x,y,k);
        } else{
            cin >> x >> y;
            cout << query(1,x,y) << '\n';
        }
    }
}