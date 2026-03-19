#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int T;
    cin >> T;
    while (T--){
        ll n,q,x,y;
        cin >> n >> q;
        vector<ll>node(n+1),p(n+1),pp(n+1);
        for (int i=2;i<=n;i++) cin >> node[i];
        for (int i=1;i<=n;i++){
            cin >> p[i];
            pp[p[i]] = i;
        }
        map<pair<int,int>,int>mp;
        for (int i=0;i<q;i++){
            int ok = 1;
            cin >> x >> y;
            ll mx = max(pp[p[x]],pp[p[y]]), mi = min(pp[p[x]],pp[p[y]]);
            while (mx != 1){
                mx /= 2;
                if (mx == mi){
                    ok = 0;
                    break;
                }
            }
            mx = max(pp[p[x]],pp[p[y]]), mi = min(pp[p[x]],pp[p[y]]);
            
            if (!ok && !mp[{mi,mx}]){
                mp[{mi,mx}] ++;
            } else if (!ok){
                mp[{mi,mx}] --;
                ok = 1;
            }
            
            // for (auto [k,v]:mp){
            //     if (v) ok = 0;
            // }

            swap(pp[p[x]],pp[p[y]]);
            swap(p[x],p[y]);
            // for (int i=1;i<=n;i++){
            //     cout << pp[i] << " \n"[i==n];
            // }
            cout << (ok?"YES\n":"NO\n");
        }
    }
}