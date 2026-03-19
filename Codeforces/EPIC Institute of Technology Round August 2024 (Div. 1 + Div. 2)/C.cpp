#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct haha{
    ll x,y;
};
ll dis(ll xa,ll ya,ll xb,ll yb){
    return (xa-xb)*(xa-xb)+(ya-yb)*(ya-yb);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        vector<haha>cd(n);
        for (int i=0;i<n;i++){
            cin >> cd[i].x >> cd[i].y;
        }
        ll xs,ys,xt,yt;
        cin >> xs >> ys >> xt >> yt;
        ll len = dis(xs,ys,xt,yt);
        int ok = 1;
        for (int i=0;i<n;i++){
            ll disc = dis(cd[i].x,cd[i].y,xt,yt);
            if (disc<=len){
                ok = 0;
            }
        }
        cout << (ok?"YES\n":"NO\n");
    }
}