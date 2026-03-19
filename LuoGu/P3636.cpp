#include <bits/stdc++.h>
using namespace std;

int bfs(int n){
    vector<int> vis(n+1,0);
    struct haha{
        int n,st;
    };
    queue<haha>Q;
    Q.push({1,0});
    while (!Q.empty()){
        int now = Q.front().n;
        int st = Q.front().st;
        Q.pop();
        if (now == n){
            return st;
        }
        if (!vis[now+1]){
            Q.push({now+1,st+1});
            vis[now+1] = 1;
        }
        if (now*2 <= n && !vis[now*2]){
            Q.push({now*2,st+1});
            vis[now*2] = 1;
        }
    }
}

int dp(int n){
    vector<int> dp(n+1,0);  
    for (int i=2;i<=n;i++){
        if (i&1) dp[i] = dp[i-1] + 1;
        else dp[i] = min(dp[i/2]+1,dp[i-1]+1);
    }
    return dp[n];
}

int main(){
    int n;
    cin >> n;
    // cout << bfs(n) << '\n';
    cout << dp(n) << '\n';
}