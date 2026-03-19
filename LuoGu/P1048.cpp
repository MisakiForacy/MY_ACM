#include <bits/stdc++.h>
using namespace std;

struct haha{
    int t,v;
};
vector<haha>a;
map<pair<int,int>,int>memo;

/*
    深搜加剪枝写法：
        对于每个物品来说，总价值的变化取决于是否取该物品
*/
int dfs(int idx,int m,int tot,int t){
    int ans = 0;
    if (memo[{idx,tot}]){
        return memo[{idx,tot}];
    }
    if (idx == m - 1){
        if (tot+a[idx].t <= t){
            memo[{idx,tot}] = a[idx].v;
            return a[idx].v;
        }
        memo[{idx,tot}] = 0;
        return 0;
    }
    if (tot + a[idx].t <= t){
        ans += max(dfs(idx+1,m,tot,t),dfs(idx+1,m,tot+a[idx].t,t)+a[idx].v);
    } else{
        ans += dfs(idx+1,m,tot,t);
    }
    memo[{idx,tot}] = ans;
    return ans;
}

/*
    动态规划写法
*/
int dp(int t,int m){
    vector<int> dp(t+1,0);
    for (int i=0;i<m;i++){
        for (int j=t;j>=a[i].t;j--){
            dp[j] = max(dp[j],dp[j-a[i].t]+a[i].v);
        }
    }
    return dp[t];
}

int main(){
    int t,m;
    cin >> t >> m;
    a.resize(m);
    for (int i=0;i<m;i++){
        cin >> a[i].t >> a[i].v;
    }
    // cout << dfs(0,m,0,t) << '\n';
    cout << dp(t,m) << '\n';
}