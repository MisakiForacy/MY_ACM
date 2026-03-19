#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int mp[11][11];
int dp[11][11][11][11];
int main(){
    int n,x,y,w;
    cin >> n;
    while (cin >> y >> x >> w){
        if (!(y && x && w)) break;
        mp[y][x] = w;
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            for (int k=1;k<=n;k++){
                for (int s=1;s<=n;s++){
                    dp[i][j][k][s]=max(max(dp[i-1][j][k-1][s],dp[i-1][j][k][s-1]),max(dp[i][j-1][k-1][s],dp[i][j-1][k][s-1]))+mp[i][j]+mp[k][s];
                    if (i==k && j==s) dp[i][j][k][s] -= mp[i][j];

                }
            }
        }
    }
    cout << dp[n][n][n][n] << '\n';
}