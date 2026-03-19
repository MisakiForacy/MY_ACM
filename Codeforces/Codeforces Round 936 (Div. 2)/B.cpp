#include <bits/stdc++.h>
#define endl '\n'
#define N (i64)(2e5 + 10)
using namespace std;
typedef long long i64;
const i64 mod = 1e9 + 7;
i64 t,n,k,sum,tot,maxn;
i64 a[N],b[N];
void solve();
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t --){
        solve();
    }
    return 0;
}
void solve(){
    cin >> n >> k;
    tot = 0, sum = 0, maxn = 0;
    for(int i = 1; i <= n; i ++)
        cin >> a[i], sum += a[i];
    b[1] = a[1];
    for(int i = 2; i <= n; i ++)
        b[i] = max(b[i - 1] + a[i], a[i]);
    for(int i = 1; i <= n; i ++)
        if(b[i] > maxn)maxn = b[i];
    // cout << maxn << ":";
    for(int i = 0; i < k; i ++){
        tot = (tot + maxn) % mod;
        maxn = (maxn * 2) % mod;
    }
    cout << ((sum + tot) + n * mod) % mod << endl;
}