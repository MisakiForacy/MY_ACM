#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        int n,a,b;
        cin >> n >> a >> b;
        vector<ll> c(n);
        ll d = __gcd(a,b);
        for (int i=0;i<n;i++){
            cin >> c[i];
            c[i] %= d;
        }
        sort(c.begin(),c.end());
        ll ans = c.back() - c[0];
        for (int i=0;i<n-1;i++){
            ans = min(c[i]+d-c[i+1],ans);
        }
        cout << ans << '\n';
    }
}