#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 1e5+10;
LL dp[2][N];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n,W;
    int v,w,m;
    cin >> n >> W;
    int lw = 0,lv = 0;
    for (int i=0;i<n;i++){
        cin >> v >> w >> m;
        for (int j=w;j<=W;j++){
            if (j/w <= m){
                dp[1][j] = max(dp[0][j-w]+v,dp[1][j-w]+v);
            } else{
                dp[1][j] = max(dp[1][j-1],dp[0][j-w]+m*v);
            }
        }
        for (int j=0;j<=W;j++){
            dp[0][j] = dp[1][j];
            cout << dp[0][j] << " \n"[j==W];
        }
    }
    cout << dp[0][W] << '\n';
}

// 0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18 19 20

// 0  0  0  0  0  0  0  0  0  3  3  3  3  3  3  3  3  3  6  6  6
// 0  0  0  0  0  0  0  0  0  5  5  5  5  5  5  5  5  5  8  8  8
// 0  0  0  0  9  9  9  9  18 18 18 18 18 18 18 18 18 23 23 23 23
// 0  8  16 24 24 24 25 33 33 33 34 42 42 42 42 42 42 42 42 42 47

// 0  0  0  0  0  0  0  0  0  3  3  3  3  3  3  3  3  3  6  6  6
// 0  0  0  0  0  0  0  0  0  5  5  5  5  5  5  5  5  5  8  8  8
// 0  0  0  0  9  9  9  9  18 18 18 18 18 18 18 18 18 23 23 23 23
// 0  8  16 24 24 24 25 33 33 33 34 42 42 42 43 51 51 51 52 60 60

// 47