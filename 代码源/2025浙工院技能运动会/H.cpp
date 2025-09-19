#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 1e5 + 10;
const int MOD = 1e9 + 7;

LL A[N];

LL inv(LL x){
    LL k = MOD - 2;
    LL res = 1;
    while (k){
        if (k & 1) (res *= x) %= MOD;
        (x *= x) %= MOD;
        k >>= 1;
    }
    return res;
}

void init(){
    A[0] = 1;
    for (int i = 1;i <= 1e5;i ++){
        A[i] = A[i - 1] * i % MOD;
    }
}

LL cal(LL n, LL m){
    if (n < m) return 0;
    return (A[n] * inv(A[m]) % MOD * inv(A[n - m]) % MOD);
}

void solve(){
    int n;
    cin >> n;
    LL ans = 0;
    for (int i = 1;i < n;i ++){
        LL u, v, w;
        cin >> u >> v >> w;
        ans += cal(n - 1, 2) * 4 % MOD * w % MOD;
        ans %= MOD;
    }
    cout << ans << '\n';
}

int main(){
    init();
    int T = 1;
    // cin >> T;
    while (T --) solve();
}