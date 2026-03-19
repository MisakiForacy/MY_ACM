#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    LL n,k;
    cin >> n >> k;
    if (n < k){
        cout << n << '\n';
    } else{
        LL ans = 0;
        while (n >= k){
            n += 1;
            n -= k;
            ans += k;
        }
        ans += n;
        cout << ans << '\n';
    }
}