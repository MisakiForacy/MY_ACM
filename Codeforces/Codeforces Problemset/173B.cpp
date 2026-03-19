#include <bits/stdc++.h>
using namespace std;
const int N = 1005;

int vis[N][N];

struct haha{
    int x,y,st;
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    memset(vis,0,sizeof(vis));
    map<int,vector<int>>cx,cy;
    int n,m;
    string s;
    cin >> n >> m;
    for (int i=1;i<=n;i++){
        cin >> s;
        for (int j=1;j<=m;j++){
            if (s[j-1]=='#'){
                cx[i].push_back(j);
                cy[j].push_back(i);
            }
        }
    }
    int ans = -1;
    queue<haha>Q;
    Q.push({0,1,0});
    while (!Q.empty()){
        int x = Q.front().x;
        int y = Q.front().y;
        int st = Q.front().st;
        Q.pop();
        if (y == n){
            ans = st;
            break;
        }
        for (int i=cx[y].size()-1;i>=0;i--){
            if (!vis[y][cx[y][i]]){
                Q.push({cx[y][i],y,st+1});
                vis[y][cx[y][i]] = 1;
            }
            cx[y].erase(find(cx[y].begin(),cx[y].end(),cx[y][i]));
        }
        if (x != 0){
            for (int i=cy[x].size()-1;i>=0;i--){
                if (!vis[cy[x][i]][x]){
                    Q.push({x,cy[x][i],st+1});
                    vis[cy[x][i]][x] = 1;    
                }
                cy[x].erase(find(cy[x].begin(),cy[x].end(),cy[x][i]));
            }
        }
    }
    cout << ans << '\n';
}