#include <bits/stdc++.h>
using namespace std;
using LL = long long;
struct node{
    LL w,l,r,base;
};
vector<node> bal;
double mlog(double x,double y){
    return __builtin_log(y) / __builtin_log(x);
}
LL dfs(int idx){
    if (bal[idx].w) return bal[idx].w;
    LL l,r;
    LL lb,rb;
    l = r = lb = rb = 0; 
    if (bal[idx].l>0) l = dfs(bal[idx].l), lb = bal[bal[idx].l].base + 1;
    else l = bal[idx].l, lb = 1;
    if (bal[idx].r>0) r = dfs(bal[idx].r), rb = bal[bal[idx].r].base + 1;
    else r = bal[idx].r, rb = 1;
    double llb = mlog(2,abs(l)) + lb;
    double rrb = mlog(2,abs(r)) + rb;
    if (llb > rrb){
        bal[idx].w = l;
        bal[idx].base = lb ++;
    } else{
        bal[idx].w = r;
        bal[idx].base = rb ++;
    }
    return bal[idx].w;
}
int main(){
    int n;
    cin >> n;
    bal.resize(n+1);
    for (int i=1;i<=n;i++){
        cin >> bal[i].l >> bal[i].r;
        bal[i].w = bal[i].base = 0;
        if (bal[i].l<0 && bal[i].r<0){
            bal[i].w = min(bal[i].l,bal[i].r);
            bal[i].base = 1;
        }
    }
    LL res = abs(dfs(1));
    string ans = "";
    while (res){
        ans.push_back(((res&1)?'1':'0'));
        res >>= 1;
    }
    reverse(ans.begin(),ans.end());
    cout << ans;
    for (int i=0;i<bal[1].base;i++) cout << 0;
}