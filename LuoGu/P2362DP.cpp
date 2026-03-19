#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        vector<int> a(n+1,0);
        vector<int> cnt(n+1,0);
        vector<int> dp(n+1,0);
        for (int i=1;i<=n;i++){
            cin >> a[i];
        }
        int Max = 0,tot;
        cnt[0] = 1;
        for (int i=1;i<=n;i++){
            for (int j=0;j<i;j++){
                if (a[i] >= a[j]){
                    dp[i] = max(dp[i],dp[j]+1);
                }
            }
            for (int j=0;j<i;j++){
                if (a[i] >= a[j] && dp[j]==dp[i]-1){
                    cnt[i] += cnt[j];
                }
            }
            if (dp[i] > Max){
                Max = dp[i];
                tot = cnt[i];
            }
        }
        cout << Max << ' ' << tot << '\n';
    }
}