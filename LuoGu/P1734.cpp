#include <bits/stdc++.h>
using namespace std;
int a[1005];
void pre(){
    for (int i=2;i<=1000;i++){
        for (int j=1;j<=i/2;j++){
            if (! (i%j)){
                a[i] += j;
            }
        }
    }
}

int main(){
    int n;
    int dp[1005];
    memset(dp,0,sizeof(dp));
    cin >> n;
    pre();
    // for (int i=1;i<=n;i++){
    //     cout << a[i] << " \n"[i==n];
    // }
    for (int i=1;i<=n;i++){
        for (int j=i;j<=n;j++){
            dp[j] = max(dp[j],dp[j-i]+a[i]);
        }
    }
    cout << dp[n] << '\n';
}