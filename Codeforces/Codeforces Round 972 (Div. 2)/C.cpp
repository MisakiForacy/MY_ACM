#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n,m;
        cin >> n >> m;
        string s[n];
        map<char,int> mp;
        string ss = "narek";
        mp['n'] = mp['a'] = mp['r'] = mp['e'] = mp['k'] = 1;
        for (int i=0;i<n;i++) cin >> s[i];
        vector<vector<ll>> dp(5,vector<ll>(n+1,-1e9));
        dp[0][0] = 0;
        ll ans = 0;
        for (int i=0;i<n;i++){
            for (int j=0;j<5;j++){
                ll cnt = 0;
                ll tot = 0;
                ll now = j;
                for (int k=0;k<m;k++){
                    if (mp.count(s[i][k])){
                        if (ss[now]==s[i][k]){
                            now = (now + 1) % 5;
                        } else{
                            cnt ++;
                        }
                        tot ++;
                    }
                }
                dp[now][i+1] = max(dp[j][i]+tot-2*cnt,dp[now][i+1]);
            }
            for (int j=0;j<5;j++){
                dp[j][i+1] = max(dp[j][i+1],dp[j][i]);
            }
            ans = max(ans,dp[0][i+1]);
        }
        for (int i=0;i<5;i++){
            ans = max(ans,dp[i][n]-2*i);
        }
        cout << ans << '\n';
    }
}