#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int MOD = 1e9+7;
LL qpower(LL a,LL k){
    LL res = 1;
    while (k){
        if (k&1) res = res * a % MOD;
        a = a * a % MOD;
        k >>= 1;
    }
    return res;
}
int main(){
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        vector<LL> a(n+1,0),b(n+1,0);
        for (int i=1;i<=n;i++){
            cin >> a[i];
        }
        stack<pair<LL,int>> stk;
        for (int i=1;i<=n;i++){
            while (!(a[i] & 1)) b[i] ++,a[i] /= 2;
            b[i] += b[i-1];
        }
        stk.push({0,0});
        LL ans = 0;
        for (int i=1;i<=n;i++){
            auto [v,id] = stk.top();
            while (id > 0 && a[i]*(1LL << b[i]-b[id]) > a[id]){
                stk.pop();
                ans -= v;
                ans += a[id];
                v = stk.top().first;
                id = stk.top().second;
            }
            LL num = a[i] * qpower(2,b[i]-b[id]);
            ans = ans + num;
            stk.push({num,i});
            cout << ans%MOD << " \n"[i==n];
        }
    }
}