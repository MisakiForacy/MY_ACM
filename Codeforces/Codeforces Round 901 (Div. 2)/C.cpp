#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int T; cin >> T;
    while (T --){
        LL n,m,ok = 0;
        LL ans = 0;
        cin >> n >> m;
        for (int i = 1;i <= 32;i ++){
            if (n * (1LL << i) % m == 0){
                ok = 1;
                break;
            }
        }
        if (ok){
            n %= m;
            while (n < m){
                ans += n;
                n *= 2;
                if (n >= m) n %= m;
                if (n == 0) break;
            }
            cout << ans << '\n';
        } else{
            cout << -1 << '\n';
        }
    }
}