#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0;i<n;i++){
        cin >> a[i];
        a[i] --;
    }
    vector<int> dp((1LL << 18),0);
    for (int i=0;i<n;i++){
        int state = (1LL << a[i]);
        dp[state] = 1;
        for (int j=i+1;j<min(n,i+18);j++){
            if (state & (1LL << a[j])){
                break;
            }
            state += (1LL << a[j]);
            dp[state] = j - i + 1;
        }
    }
    for (int i=0;i<(1LL << 18);i++){
        for (int j=0;j<18;j++){
            if (i & (1LL << j)){
                dp[i] = max(dp[i],dp[i ^ (1LL << j)]);
            }
        }
    }
    int ans = 0;
    for (int i=0;i<(1LL << 18);i++){
        ans = max(ans,dp[i] + dp[i^((1LL << 18)-1)]);
    }
    cout << ans << '\n';
}