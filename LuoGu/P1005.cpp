#include <bits/stdc++.h>
using namespace std;
const int N = 100;

int main(){
    int n,m;
    cin >> n >> m;
    for (int i=0;i<n;i++){
        vector<int> a(m+2,0);
        for (int j=1;j<=m;j++) cin >> a[i];
        int dp[N][N];
        for (int i=0;i<100;i++){
            for (int j=0;j<100;j++){
                dp[i][j] = 0;
            }
        }
        for (int i=1;i<=m;i++){
            for (int j=m;j>=i;j--){
                dp[i][j] = max(dp[i-1][j]+)
            }
        }
    }
}