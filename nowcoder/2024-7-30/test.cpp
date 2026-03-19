#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
const ll inf = 0x3f3f3f3f3f;
struct haha{
    int n,id;
};
bool cmp(haha a,haha b){
    return a.n < b.n;
}
int main(){
    int n,k,q;
    while (cin >> n >> k){
        if (!(n&&k)) break;
        vector<ll>a(n+1);
        vector<haha>pre(n+1,{0,0});
        for (int i=1;i<=n;i++){
            cin >> a[i];
            pre[i].n = pre[i-1].n + a[i];
            pre[i].id = i;
        }
        sort(pre.begin(),pre.end(),cmp);
        while (k--){
            cin >> q;
            ll mi, lo, hi;
            ll ans,ansl,ansr,dat;
            lo = 0, hi = 1, mi = inf;
            while (lo<=n&&hi<=n&&mi>0){
                dat = pre[hi].n - pre[lo].n;
                if (labs(dat-q)<mi){
                    mi = labs(dat-q);
                    ans = dat;
                    ansr = pre[hi].id;
                    ansl = pre[lo].id;
                }
                if (dat>q) lo ++;
                else if (dat<q) hi ++;
                else break;
                if (hi==lo) hi ++;
            }
            if (ansr < ansl) swap(ansr,ansl);
            cout << ans << ' ' << ansl+1 << ' ' << ansr << '\n';
        }
    }
}