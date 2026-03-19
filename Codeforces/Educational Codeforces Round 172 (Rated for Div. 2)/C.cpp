#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        LL n,k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<LL> a(n+1,0);
        vector<LL> pre(n+1,0);
        for (int i=1;i<=n;i++){
            a[i] = (s[i-1] == '1' ? 1 : -1);
        }
        for (int i=1;i<=n;i++){
            pre[i] = pre[i-1] + a[i];
        }
        auto check = [&](LL x) -> bool{
            LL pos = n;
            LL ans = 0;
            while (-- x){
                LL id = pos - 1;
                LL Max = pre[pos] - pre[id];
                for (int i=x;i<id;i++){
                    if (pre[pos]-pre[i] >= Max){
                        Max = pre[pos] - pre[i];
                        id = i;
                    }
                }
                ans += (pre[pos]-pre[id]) * x;
                pos = id;
            }
            return (ans >= k);
        };
        LL lo, hi;
        lo = 1, hi = n;
        while (lo <= hi){
            LL mid = lo + hi >> 1;
            if (check(mid)) hi = mid - 1;
            else lo = mid + 1;
        }
        if (lo > n) cout << -1 << '\n';
        else cout << lo << '\n';
    }
}