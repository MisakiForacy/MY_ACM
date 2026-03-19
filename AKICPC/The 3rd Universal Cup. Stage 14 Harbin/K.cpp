#include <bits/stdc++.h>
using namespace std;
using LL = long long;
struct node{
    LL w,l,r,d,id;
    bool operator < (const node&that) const {
        return w < that.w;
    }
};
int main(){
    LL n,m;
    cin >> n >> m;
    LL res1 = m, res2 = m;
    vector<node> a(n);
    vector<node> b(n);
    priority_queue<node> Q1,Q2;
    LL Min = LLONG_MAX,Max = LLONG_MIN,id1 = -1,id2 = -1;
    for (LL i=0;i<n;i++){
        cin >> a[i].w >> a[i].l >> a[i].r;
        b[i].w = a[i].w;
        b[i].l = a[i].l;
        b[i].r = a[i].r;
        b[i].id = i;
        a[i].id = i;
        if (Min > a[i].w){
            Min = a[i].w;
            id1 = i;
        }
        if (Max < a[i].w){
            Max = a[i].w;
            id2 = i;
        }
    }
    a[id1].l = 0, a[id1].r = m;
    b[id2].l = 0, b[id2].r = m;
    for (LL i=0;i<n;i++){
        a[i].d = a[i].l;
        res1 -= a[i].d;
        Q1.push({a[i].w,a[i].l,a[i].r,a[i].d,a[i].id});
    }
    for (LL i=0;i<n;i++){
        b[i].d = b[i].l;
        res2 -= b[i].d;
        Q2.push({b[i].w,b[i].l,b[i].r,b[i].d,b[i].id});
    }
    while (res1){
        auto [w,l,r,d,id] = Q1.top();
        if (d < r){
            if (res1 > r-d){
                res1 -= r - d;
                a[id].d = r;
            } else{
                a[id].d += res1;
                res1 = 0;
            }
        }
        Q1.pop();
    }
    while (res2){
        auto [w,l,r,d,id] = Q2.top();
        if (d < r){
            if (res2 > r-d){
                res2 -= r - d;
                b[id].d = r;
            } else{
                b[id].d += res2;
                res2 = 0;
            }
        }
        Q2.pop();
    }
    LL ans1 = 0,ans2 = 0;
    for (LL i=0;i<n;i++){
        ans1 += a[i].d * a[i].w;
        ans2 += b[i].d * b[i].w;
    }
    cout << max(ans1,ans2) << '\n';
}