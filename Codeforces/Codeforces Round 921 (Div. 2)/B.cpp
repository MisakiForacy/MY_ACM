#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define debug(x) cerr << #x << ':' << x << ' ';
#define nl cerr << '\n';
using namespace std;
const int N = 1e5 + 10; // 需调整
using LL = long long;
const LL inf = LLONG_MAX;
const LL MOD7 = 1e9 + 7;
const LL MOD3 = 998244353;

void fxy_ac(){
    LL x, n;
    cin >> x >> n;
    LL ans = 1;
    for (LL i = 1;i <= sqrt(x);i ++){
        if (x % i == 0){
            if (i <= x / n) ans = max(ans, i);
            if (x / i <= x / n) ans = max(ans, x / i);
        }
    }
    cout << ans << '\n';
}

void brute(){ // 暴力

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T; // 需调整
    while (T --){
        fxy_ac();
        // brute();
    }
}