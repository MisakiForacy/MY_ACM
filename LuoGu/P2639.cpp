#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int h,n;
    cin >> h >> n;
    vector<int> a(n);
    vector<int> dp(h+1,0);
    for (int i=0;i<n;i++) cin >> a[i];
    for (int i=0;i<n;i++){
        for (int j=h;j>=a[i];j--){
            dp[j] = max(dp[j],dp[j-a[i]]+a[i]);
        }
    }
    cout << dp[h] << '\n';
}
