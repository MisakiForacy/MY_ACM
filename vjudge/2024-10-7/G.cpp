#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    LL n,W,k;
    cin >> n >> W >> k;
    struct node{
        LL w,v;
        bool operator < (const node&that) const {
            return v > that.v;
        }
    };
    vector<node> obj(n);
    for (int i=0;i<n;i++){
        cin >> obj[i].w >> obj[i].v;
    }
    sort(obj.begin(),obj.end(),[&](node x,node y){    
        return x.w < y.w;
    });
    priority_queue<node> Q;
    LL suf = 0;
    vector<LL> suf_v(n+1,0);
    for (int i=n-1;i>=0;i--){
        Q.push(obj[i]);
        suf += obj[i].v;
        if (Q.size() > k){
            suf -= Q.top().v;
            Q.pop();
        }
        suf_v[i] = suf;
    }
    LL ans = suf_v[0];
    vector<LL> dp(W+1,0);
    dp[0] = 0;
    for (int i=0;i<n;i++){
        for (int j=W;j>=obj[i].w;j--){
            dp[j] = max(dp[j],dp[j-obj[i].w]+obj[i].v);
            ans = max(ans,dp[j]+suf_v[i+1]);
        }
        // cout << dp[W] << ' ' << suf_v[i+1] << '\n';
    }
    cout << ans << '\n';
}