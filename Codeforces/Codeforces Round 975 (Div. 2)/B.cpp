#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int T;
    cin >> T;
    while (T--){
        ll n,q;
        cin >> n >> q;
        vector<ll> a(n);
        map<ll,ll> ans;
        for (int i=0;i<n;i++){
            cin >> a[i];
        }
        vector<ll> b(n),c(n);
        b[0] = b[n-1] = n - 1;
        ans[n-1] += 2;
        for (int i=1;i<n-1;i++){
            b[i] = (n-i) * i + (n-i-1);
            ans[b[i]] ++;
        }
        for (int i=1;i<n;i++){
            c[i] = (n-i) * i;
            ans[c[i]] += a[i] - a[i-1] - 1;
        }
        for (int i=0;i<q;i++){
            ll k;
            cin >> k;
            cout << ans[k] << " \n"[i==q-1];
        }
    }
}