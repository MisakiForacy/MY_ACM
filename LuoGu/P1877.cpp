#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,beg,Max;
    cin >> n >> beg >> Max;
    vector<int> c(n+1);
    for (int i=1;i<=n;i++) cin >> c[i];
    int dp[n+1][Max+1];
    for (int i=0;i<=n;i++){
        for (int j=0;j<=Max;j++){
            dp[i][j] = 0;
        }
    }
    dp[0][beg] = 1;
    for (int i=1;i<=n;i++){
        for (int j=0;j<=Max;j++){
            if (dp[i-1][j]){
                if (j-c[i]>=0) dp[i][j-c[i]] = 1;
                if (j+c[i]<=Max) dp[i][j+c[i]] = 1;
            }
        }
    }
    int ans = -1;
    for (int i=0;i<=Max;i++){
        if (dp[n][i]){
            ans = i;
        }
    }
    cout << ans << '\n';
}