#include <bits/stdc++.h>
#define lc(x) x<<1
#define rc(x) x<<1|1
using namespace std;
typedef long long ll;
const int N = 2e5+10;
struct node{
    ll l,r,v,lazy;
};
vector<node> tr(4*N);
vector<ll> a(N);
void pushup(int p){
    tr[p].v = max(tr[lc(p)].v,tr[rc(p)].v);
}
void build(int p,int l,int r){
    tr[p] = {l,r,a[l],0};
    if (l==r) return;
    int m = (l+r) >> 1;
    build(lc(p),l,m);
    build(rc(p),m+1,r);
    pushup(p);
}
void update(int p,int x,int y,int k){
    if (x==tr[p].l && tr[p].r==y){
        if (tr[p].v < k){
            tr[p].v = k;
        }
        return;
    }
    int m = (tr[p].l+tr[p].r) >> 1;
    // pushdown(p);
    if (x <= m) update(lc(p),x,y,k);
    if (y > m) update(rc(p),x,y,k);
    pushup(p);
}
ll query(int p,int x,int y){
    if (x<=tr[p].l && tr[p].r<=y){
        return tr[p].v;
    }
    int m = (tr[p].l+tr[p].r) >> 1;
    ll ans = 0;
    if (x <= m) ans = max(ans,query(lc(p),x,y));
    if (y > m) ans = max(ans,query(rc(p),x,y));
    return ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n,m;
    cin >> n >> m;
    for (int i=1;i<=n;i++) cin >> a[i];
    build(1,1,n);
    for (int i=0;i<m;i++){
        char op;
        int x,y,k;
        cin >> op;
        if (op=='U'){
            cin >> x >> k;
            update(1,x,x,k);
        } else{
            cin >> x >> y;
            cout << query(1,x,y) << '\n';
        }
    }
}