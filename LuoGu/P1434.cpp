#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int dx[] = {0,1,0,-1};
const int dy[] = {-1,0,1,0};
int mp[105][105];
map<pair<int,int>,int> cut;
int dfs(int x,int y){
    if (cut[{x,y}]) return cut[{x,y}];
    int len = 1;
    for (int k=0;k<4;k++){
        if (mp[x+dx[k]][y+dy[k]] > mp[x][y]){
            len = max(len,dfs(x+dx[k],y+dy[k])+1);
        }
    }
    cut[{x,y}] = len;
    return len;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n,m;
    cin >> n >> m;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            cin >> mp[i][j];
        }
    }
    int ans = 0;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            ans = max(ans,dfs(i,j));
        }
    }
    cout << ans << '\n';
}