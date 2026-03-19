#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int MOD = 1e9+7;
int main(){
    int T;
    cin >> T;
    while (T--){
        string s;
        cin >> s;
        int n = s.length();
        s = ' ' + s;
        vector<int> pre(n+1,0);
        map<LL,LL> mp;
        mp[0] += n + 1;
        for (int i=1;i<=n;i++){
            pre[i] = pre[i-1] + (s[i] == '1'?1:-1);
            mp[pre[i]] += n-i+1;
        }
        LL ans = 0;
        for (int i=0;i<=n;i++){
            mp[pre[i]] -= n-i+1;
            ans = ans + ((i+1)%MOD * mp[pre[i]]%MOD)%MOD;
            ans %= MOD;
        }
        cout << ans << '\n';
    }
}