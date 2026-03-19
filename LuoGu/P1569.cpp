#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int n;
    cin >> n;
    vector<LL> a(n+1,0);
    vector<LL> pre(n+1,0);
    vector<LL> dp(n+1,0);
    for (int i=1;i<=n;i++){
        cin >> a[i];
        pre[i] = pre[i-1] + a[i];
    }
    if (pre[n]<0){
        cout << "Impossible\n";
    } else{
        for (int i=1;i<=n;i++){
            for (int j=0;j<i;j++){
                if (pre[j]>=0 && pre[i]-pre[j]>=0){
                    dp[i] = max(dp[i],dp[j] + 1);
                }
            }
        }
        cout << dp[n] << '\n';
    }
}