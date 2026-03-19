#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
using namespace std;
using LL = long long;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        vector<LL> a(n+1,0);
        vector<LL> pre(n+1,0);
        vector<LL> dp(n+1,0);
        map<int,vector<int>> mp;
        for (int i=1;i<=n;i++){
            cin >> a[i];
            pre[i] = pre[i-1] + a[i];
        }
        for (int i=1;i<=n;i++){
            mp[pre[n]-pre[i-1]].push_back(i);
        }
        for (int i=1;i<=n;i++){
            dp[i] = dp[i-1] + (!a[i]);
            if (a[i]){
                if (mp.count(pre[n]-pre[i])){
                    auto idx = lower_bound(all(mp[pre[n]-pre[i]]),i);
                    if (idx != mp[pre[n]-pre[i]].begin()){
                        idx --;
                        int x = *idx;
                        dp[i] = max(dp[i],dp[x-1]+1);
                    }
                }
            }
        }
        cout << dp[n] << '\n';
    }
}