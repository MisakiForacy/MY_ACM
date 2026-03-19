#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
struct info{
    i64 n,s;
};
i64 n,m,i,j;
vector<info>h,res;
static inline bool cmp(const info &a,const info &b){
    if(a.s != b.s)return a.s > b.s;
    return a.n < b.n;
}
int main(){
    cin >> n >> m;
    h.resize(n);
    for(i=0;i<n;i++)cin >> h[i].n >> h[i].s;
    sort(h.begin(),h.end(),cmp);
    m = (i64)(m * 1.5);
    for(i=0;i<m;i++){
        res.push_back({h[i].n,h[i].s});
    }
    for(i=m;i<n;i++){
        if(h[i].s == h[i-1].s){
            res.push_back({h[i].n,h[i].s});
        }
        else break;
    }
    cout << h[i-1].s << " " << res.size() << endl; 
    for(i=0;i<res.size();i++){
        cout << res[i].n << " " << res[i].s << endl;
    }
    return 0;
}