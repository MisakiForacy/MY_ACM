#include <bits/stdc++.h>
#define lc p << 1
#define rc p << 1 | 1
#define mid l + r >> 1
using namespace std;
typedef long long LL;
const int N = 1e5+10;
struct SegTree{
    int l,r;
    int dat;
} tr[4*N];
int a[N];
void build(int p,int l,int r){
    tr[p].l = l, tr[p].r = r;
    if (l == r){
        tr[p].dat = a[l];
        return;
    }
    build(lc,l,mid);
    build(rc,mid+1,r);
    tr[p].dat = tr[lc].dat + tr[rc].dat;
}
void change(int p,int id,int x){
    if (tr[p].l == tr[p].r){
        tr[p].dat = x;
        return;
    }
    if (id <= mid) change(lc,id,x);
    else change(rc,id,x);
    tr[p].dat = tr[lc].dat + tr[rc].dat;
}
SegTree query(int p,int l,int r){
    if (l == tr[p].l && r == tr[p].r){
        return tr[p];
    }
    
}
int main(){

}