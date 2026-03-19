#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n,l,r;
    cin >> n >> l >> r;
    vector<LL> a(n+r+1,0);
    vector<LL> dp(n+r+1,LLONG_MIN);
    for (int i=0;i<=n;i++){
        cin >> a[i];
    }
    dp[0] = a[0];
    LL ans = LLONG_MIN;
    struct node{
        LL id,val;
        bool operator < (const node&that) const {
            return val < that.val;
        }
    };
    priority_queue<node> Q;
    for (int i=0;i<=n+r;i++){
        if (i - l >= 0){
            Q.push({i-l,dp[i-l]});
            while (Q.top().id < i-r){
                Q.pop();
            }
            dp[i] = max(dp[i],Q.top().val+a[i]);
        }
        if (i > n){
            ans = max(ans,dp[i]);
        }
    }
    cout << ans << '\n';
}