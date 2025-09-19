#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve(){
    int a, b;
    cin >> a >> b;
    int ans = 0;
    int v1 = (a | b) - b + 1;
    int v2 = (a | b) - a + 1;
    for (int i = 0;i <= 20;i ++){
        if (((a >> i) & 1) && !((b >> i) & 1)){
            int x = (((b >> (i + 1)) << (i + 1)) | (a ^ ((a >> (i + 1)) << (i + 1)))) - b;
            int y = (((a >> i) ^ 1) << i) + (1LL << (i + 1)) - a;
            if (x < y){
                ans += x;
                b = (((b >> (i + 1)) << (i + 1)) | (a ^ ((a >> (i + 1)) << (i + 1))));
            } else if (y <= x){
                ans += y;
                a = (((a >> i) ^ 1) << i) + (1LL << (i + 1));
            }
            // cout << a << ' ' << b << ' ' << ans << '\n';
        }
    }
    if (a != b) ans ++;
    cout << min({ans, v1, v2}) << '\n';
}

int main(){
    int T = 1;
    cin >> T;
    while (T --) solve();
}