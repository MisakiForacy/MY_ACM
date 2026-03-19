#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int c[40],w[40],vis[40],id[40];
int cont[40][40];
int n,m,u,v;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    memset(id,-1,sizeof(id));
    cin >> n >> m;
    int len = 0;
    for (int i=1;i<=n;i++){
        cin >> c[i];
        if (vis[c[i]] == 1){
            id[c[i]] = len ++;
        }
        vis[c[i]] ++;
    }
    for (int i=1;i<=n;i++) cin >> w[i];
    for (int i=0;i<m;i++){
        cin >> u >> v;
        cont[u][v] = 1;
    }
    int dp[n+1][(1LL << len)];
    memset(dp,0,sizeof(dp));
    cont[0][1] = 1;
    for (int i=0;i<(1LL << len);i++){
        for (int j=0;j<=n;j++){
            for (int k=j+1;k<=n;k++){
                if (cont[j][k]){
                    if ( id[c[k]] != -1 && !(i & (1LL << id[c[k]])) ){
                        dp[k][i | (1LL << id[c[k]])] = max(dp[k][i | (1LL << id[c[k]])],dp[j][i]+w[c[k]]);
                    } else if ( id[c[k]] == -1 ){
                        dp[k][i] = max(dp[j][i]+w[c[k]],dp[k][i]);
                    } else if ( id[c[k]] != -1 && (i & (1LL << id[c[k]])) ){
                        dp[k][i] = max(dp[k][i],dp[j][i]);
                    }
                }
            }
        }
    }
    for (int i=1;i<=n;i++){
        int Max = 0;
        for (int j=0;j<(1LL << len);j++){
            Max = max(Max,dp[i][j]);
        }
        cout << Max << '\n';
    }
}