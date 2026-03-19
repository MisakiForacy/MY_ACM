#include <bits/stdc++.h>
using namespace std;
int main(){
    int c,h,x;
    cin >> c >> h;
    int dp[c+1];
    for (int i=0;i<=c;i++) dp[i] = 0;
    for (int i=0;i<h;i++){
        cin >> x;
        for (int j=c;j>=x;j--){
            dp[j] = max(dp[j],dp[j-x]+x);
        }
    }
    cout << dp[c] << '\n';
}