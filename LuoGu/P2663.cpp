#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int a[105];
int dp[105][5005][55];
// dp(i,j,k) i表示处理到了第几个数
//           j表示背包容量
//           k表示已经取了几个数
int main(){
    int n;
    int sum = 0;
    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> a[i];
        sum += a[i];
    }
    int half = sum / 2 + sum % 2;
    for (int i=1;i<=n;i++){
        for (int j=half;j>=0;j--){
            for (int k=1;k<=min(n/2,i);k++){
                if (j >= a[i]){
                    dp[i][j][k] = max(dp[i-1][j-a[i]][k-1]+a[i],dp[i-1][j][k]);
                } else{
                    dp[i][j][k] = dp[i-1][j][k];
                }
            }
        }
    }
    cout << dp[n][half][n/2] << '\n';
}