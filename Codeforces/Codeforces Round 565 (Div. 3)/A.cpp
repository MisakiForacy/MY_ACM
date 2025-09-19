#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int T;
    cin >> T;
    while (T --){
        LL n;
        cin >> n;
        LL ans = 0;
        while (n % 5 == 0) n /= 5, n *= 4, ans ++;
        while (n % 3 == 0) n /= 3, n *= 2, ans ++;
        while (n % 2 == 0) n /= 2, ans ++;
        if (n == 1){
            cout << ans << '\n';
        } else{
            cout << -1 << '\n';
        }
    }
}