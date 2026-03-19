#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        ll n,m,ans = 0;
        cin >> n >> m;
        vector<ll>a(n),p(n);
        map<ll,ll>mp;
        for (int i=0;i<n;i++) cin >> a[i];
        for (int i=0;i<n;i++) cin >> p[i], mp[a[i]] = p[i];
        for (auto [k,v]:mp){
            ll mm = m;
            if (mp.count(k+1)){
                ll h1 = min(v,mm / k);
                ll h2 = min(mp[k+1],((mm - h1 * k) / (k+1)));
                ans = max(ans,min(mm,min(h1,mp[k+1]-h2) + h1 * k + h2 * (k+1)));
            } else{
                ans = max(ans,k * min(mm / k,v));
            }
        }
        cout << ans << '\n';
    }
}