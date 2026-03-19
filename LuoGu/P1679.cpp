#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll fac[101];
void f(){
    for (int i=1;i<=100;i++){
        fac[i] = i * i * i * i;
    }
}
int main(){
    f();
    int m;
    cin >> m;
    int dp[m+1];
    for (int i=0;i<=m;i++) dp[i] = m;
    dp[0] = 0;
    for (int i=1;i<=100;i++){
        for (int j=0;j<=m;j++){
            if (j >= fac[i]){
                dp[j] = min(dp[j],dp[j-fac[i]]+1);
            }
        }
    }
    cout << dp[m] << '\n';
}