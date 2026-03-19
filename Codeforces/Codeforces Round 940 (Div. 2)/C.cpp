#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
#define mod (i64)(1e9+7)
#define N (i64)(1e6+10)
typedef long long i64;
static inline void solve();
i64 f[N],n,k,t,x,y,i;
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0),std::cout.tie(0);
    int t;
    std::cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
static inline void solve(){
    std::cin >> n >> k;
    for(i = 0; i < k; i++){
        std::cin >> x >> y;
        if(x==y)n--;
        else n -= 2;
    }
    f[0] = f[1] = 1;
    for(i = 2; i <= n; i++){
        f[i] = f[i-1] + f[i-2]*2ll%mod*(i-1)%mod;
    }
    std::cout << f[n]%mod << endl;
}