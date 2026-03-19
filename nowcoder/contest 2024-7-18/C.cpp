#include <bits/stdc++.h>
using namespace std;
const int dx[] = {0,1,0,-1};
const int dy[] = {-1,0,1,0};
int dfs(vector<vector<int>>&mp,int x,int y){
    mp[y][x] = 0;
    for(int i=0;i<4;i++){
        if(mp[y+dy[i]][x+dx[i]]){
            return dfs(mp,x+dx[i],y+dy[i])+1;
        }
    }
    return 0;
}
int main(){
    int n,cnt,mx;
    cin >> n;
    vector<vector<int>>mp(4,vector<int>(n+2,0));
    string s1,s2;
    cin >> s1 >> s2;
    cnt = mx = 0;
    for (int i=1;i<=n;i++){
        mp[1][i] = (s1[i-1]=='R');
        mp[2][i] = (s2[i-1]=='R');
        if (s1[i-1]=='R') cnt ++;
        if (s2[i-1]=='R') cnt ++;
    }
    for (int i=1;i<3;i++){
        for (int j=1;j<=n;j++){
            if (mp[i][j]){
                cnt = dfs(mp,j,i);
            }
            mx = max(mx,cnt);
        }
    }
    cout << mx << '\n';
}