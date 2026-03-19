#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int T;
    cin >> T;
    while (T--){
        ll n,k;
        cin >> n >> k;
        if (k >= n){
            cout << 1 << '\n';
        } else{
            ll ans = n;
            for (ll i=2;i<=min((ll)sqrt(n),k);i++){
                if (!(n%i)){
                    if (n/i <= k){
                        ans = min(ans,i);
                    }
                    if (i <= k){
                        ans = min(ans,n/i);
                    }
                }
            }
            cout << ans << '\n';
        }
    }
}