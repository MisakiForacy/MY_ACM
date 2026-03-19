#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int T;
    cin >> T;
    while (T--){
        ll n;
        cin >> n;
        n ++;
        ll ans = 0;
        while (n){
            n >>= 1;
            ans ++;
        }
        cout << ans-1 << '\n';
    }
}