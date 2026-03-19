#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    LL n,a;
    cin >> n;
    struct node{
        double a,b;
    };
    node dp[n+1];
    dp[0].a = dp[0].b = 100;
    for (int i=1;i<n;i++){
        cin >> a;
        dp[i].b = max(dp[i-1].b,dp[i-1].a*a);
        dp[i].a = max(dp[i-1].a,dp[i-1].b/a);
    }
    cin >> a;
    cout << fixed << setprecision(2) << max(dp[n-1].a,dp[n-1].b/a) << '\n';
}