#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int n,l,r;
    while (cin >> n >> l >> r){
        vector<int> a(n+1,0);
        vector<int> pre(n+1,0);
        int dp[n+1][n+1][max(l,r)+1];
        memset(dp,0x3f,sizeof(dp));
        for (itn i=1;i<=n;i++){
            cin >> a[i];
            pre[i] = pre[i-1] + a[i];
            dp[i][i][1] = 0;
        }
        
    }
}