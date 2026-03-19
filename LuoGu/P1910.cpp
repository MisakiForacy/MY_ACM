#include <bits/stdc++.h>
using namespace std;
const int N = 1001;
int main(){
    int n,m,x;
    cin >> n >> m >> x;
    int dp[m+1][x+1];
    for (int i=0;i<=m;i++){
        for (int j=0;j<=x;j++){
            dp[i][j] = 0;
        }
    }
    int a,b,c;
    for (int i=0;i<n;i++){
        cin >> a >> b >> c;
        for (int j=m;j>=b;j--){
            for (int k=x;k>=c;k--){
                dp[j][k] = max(dp[j][k],dp[j-b][k-c]+a);
            }
        }
    }
    cout << dp[m][x] << '\n';
}