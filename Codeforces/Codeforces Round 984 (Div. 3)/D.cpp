#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int dx[] = {1,0,-1,0};
const int dy[] = {0,1,0,-1};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        int n,m;
        cin >> n >> m;
        string s;
        vector<vector<char>> mp(n+1,vector<char> (m+1));
        vector<vector<int>> vis(n+2,vector<int> (m+2,1));
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                vis[i][j] = 0;
            }
        }
        for (int i=1;i<=n;i++){
            cin >> s;
            s = ' ' + s;
            for (int j=1;j<=m;j++){
                mp[i][j] = s[j];
            }
        }
        string line;
        int cnt = 0;
        for (int i=1;i<=min(n,m)/2;i++){
            int k = 0;
            int x,y;
            x = y = i;
            line = "";
            while (1){
                vis[y][x] = 1;
                line.push_back(mp[y][x]);
                if (k == 3 && vis[y+dy[k]][x+dx[k]]){
                    break;
                }
                if (vis[y+dy[k]][x+dx[k]]){
                    k ++;
                    k %= 4;
                }
                x += dx[k], y += dy[k];
                if (k == 3 && vis[y][x]){
                    break;
                }
            }
            line += line.substr(0,3);
            for (int j=0;j<line.length()-3;j++){
                if (line[j]=='1' && line[j+1]=='5' && line[j+2]=='4' && line[j+3]=='3'){
                    cnt ++;
                }
            }
        }
        cout << cnt << '\n';
    }
}