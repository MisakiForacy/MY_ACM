#include <bits/stdc++.h>
using namespace std;
struct haha{
    int a,b;
};
int main(){
    int n,k;
    cin >> n >> k;
    vector<haha> a(n);
    int ans,tot;
    ans = tot = 0;
    for (int i=0;i<n;i++){
        cin >> a[i].a >> a[i].b;
        if (a[i].b <= k){
            ans += a[i].a;
            tot += k - a[i].b;
        }
    }
    int dp[tot + 1];
    for (int i=0;i<=tot;i++){
        dp[i] = 0;
    }
    for (int i=0;i<n;i++){
        if (a[i].b > k){
            for (int j=tot;j>=0;j--){
                if (j < a[i].b-k) break;
                dp[j] = max(dp[j],dp[j-a[i].b+k]+a[i].a);
            }
        }
    }
    cout << dp[tot] + ans << '\n';
}