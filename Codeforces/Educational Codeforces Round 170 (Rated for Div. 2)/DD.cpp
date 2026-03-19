#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int n,m;
    cin >> n >> m;
    vector<int> r(n+1,0);
    vector<int> S(n+1,0);
    vector<int> I(n+1,0);
    vector<int> dp(n+2,0);
    int cnt = 0;
    for (int i=1;i<=n;i++){
        cin >> r[i];
        S[i] += S[i-1] + (r[i]==0);
        I[i] += I[i-1] + (r[i]==0);
        if (r[i]==0){
            cnt ++;
        }
    }
    int ans = 0;
    for (int i=n;i>=1;i--){
        if (r[i] > 0){
            if (r[i] <= I[i]){
                dp[i] += 1;
            }
        } else if (r[i] < 0){
            if (-r[i] <= S[i]){
                dp[i] += 1;
            }
        }
        dp[i] += dp[i+1];
        ans = max(dp[i],ans);
    }
    cout << ans << '\n';
}