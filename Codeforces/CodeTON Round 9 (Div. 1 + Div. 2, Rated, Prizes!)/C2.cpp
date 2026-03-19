#include <bits/stdc++.h>
using namespace std;
using LL = long long;
void solve(){
    LL n,m;
    LL ans = 0;
    cin >> x >> m;
    if (m >= x){
        ans += (m-x) / x;
        
    }
    for (int i=1;i<=min(x,m);i++){
        LL p = x^i;
        if (p%y==0){
            ans ++;
        }
    }
    if (m > x){
        ans --;
    }
    cout << ans << '\n';
    return;
}
int main(){
    int T = 1;
    cin >> T;
    while (T--){
        solve();
    }
}