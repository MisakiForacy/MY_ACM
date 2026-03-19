#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e9+7;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n,k;
        cin >> n >> k;
        string s;
        cin >> s;
        ll cnt = 0;
        ll n1 = inf, n2 = -inf;
        for (ll i=0;i<n;i++){
            if (s[i]=='1'){
                cnt ++;
            }
        }
        for (int i=0;i<n;i++){
            if (s[i]=='1'){
                n1 = i;
                break;
            }
        }
        for (int i=n-1;i>=0;i--){
            if (s[i]=='1'){
                n2 = i;
                break;
            }
        }
        ll ans = cnt * 11;
        if (n1 != n2){
            if (n-n2-1<=k){
                ans -= 10;
                k -= (n-n2-1);
            }
            if (n1<=k){
                ans -= 1;
            }
        } else{
            if (n-n2-1<=k){
                ans -= 10;
            } else if (n1<=k){
                ans -= 1;
            }
        }
        cout << ans << '\n';
    }
}