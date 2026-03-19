#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct haha{
    ll v,w,q;
};
struct lala{
    ll v,w;
};
int main(){
    int n,m;
    cin >> n >> m;
    vector<haha>a(m+1);
    map<int,vector<lala>>sub;
    for (int i=1;i<=m;i++){
        cin >> a[i].v >> a[i].w >> a[i].q;
        if (a[i].q!=0){
            sub[a[i].q].push_back({a[i].v,a[i].w});
        }
    }
    vector<ll> dp(n+1,0);
    for (int i=1;i<=m;i++){
        // cout << a[i].v << ' ' << a[i].w << '\n';
        for (int j=n;a[i].q==0&&j>=a[i].v;j--){
            dp[j] = max(dp[j],dp[j-a[i].v]+a[i].v*a[i].w);
            if (sub.count(i)){
                if (sub[i].size()==1 && j >= a[i].v+sub[i][0].v){
                    dp[j] = max(dp[j],dp[j-a[i].v-sub[i][0].v]+a[i].v*a[i].w+sub[i][0].v*sub[i][0].w);
                }
                if (sub[i].size()==2){
                    if (j >= a[i].v+sub[i][0].v){
                        dp[j] = max(dp[j],dp[j-a[i].v-sub[i][0].v]+a[i].v*a[i].w+sub[i][0].v*sub[i][0].w);
                    }
                    if (j >= a[i].v+sub[i][1].v){
                        dp[j] = max(dp[j],dp[j-a[i].v-sub[i][1].v]+a[i].v*a[i].w+sub[i][1].v*sub[i][1].w);
                    }
                    if (j >= a[i].v+sub[i][0].v+sub[i][1].v){
                        dp[j] = max(dp[j],dp[j-a[i].v-sub[i][0].v-sub[i][1].v]+a[i].v*a[i].w+sub[i][0].v*sub[i][0].w+sub[i][1].v*sub[i][1].w);
                    }
                }
            }
            // cout << dp[j] << " \n"[j==a[i].w]
        }
    }
    cout << dp[n] << '\n';
}