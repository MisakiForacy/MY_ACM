struct SegmentTree{
    #define lc p << 1
    #define rc p << 1 | 1
    struct node{
        int l,r,val;
        node(int x = 0){
            l = r = val = x;
        }
        node friend operator+(node a, node b){
            node res;
            res.val = a.val + b.val;
            res.l = min(a.l,b.l);
            res.r = max(a.r,b.r);
            return res;
        }
    };
    vector<node> tr;
    vector<int> a;
    SegmentTree(int N){
        N ++;
        tr.resize(4*N);
        a.resize(N);
    };
    int mid(int l,int r){return l + r >> 1;}
    void build(int p,int l,int r){
        tr[p].l = l, tr[p].r = r;
        if (l == r){
            tr[p].val = a[l];
            return;
        }
        build(lc,l,mid(l,r));
        build(rc,mid(l,r)+1,r);
        tr[p] = tr[lc] + tr[rc];
    }
    void change(int p,int id,int x){
        if (tr[p].l == tr[p].r){
            tr[p].val = x;
            return;
        }
        int m = mid(tr[p].l,tr[p].r);
        if (id <= m) change(lc,id,x);
        else change(rc,id,x);
        tr[p] = tr[lc] + tr[rc];
    }
    node query(int p,int l,int r){
        if (l <= tr[p].l && tr[p].r <= r) return tr[p];
        node res;
        int m = mid(tr[p].l,tr[p].r);
        if (l <= m) res = res + query(lc,l,min(r,m));
        if (r > m) res = res + query(rc,max(l,m+1),r);
        return res;
    }
};