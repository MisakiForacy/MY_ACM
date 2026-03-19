#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
const int dx[] = {0,1,0,-1};
const int dy[] = {1,0,-1,0};
struct haha{
    int x,y,st;
};
int mp[105][105];
queue<haha>Q;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        for (int i=0;i<105;i++){
            for (int j=0;j<105;j++){
                mp[i][j] = -2;
            }
        }
        int n,m,x,y;
        string s;
        cin >> n >> m;
        for (int i = 1;i<=n;i++){
            cin >> s;
            for (int j = 1;j<=m;j++){
                mp[i][j] = ((s[j-1]=='.'||s[j-1]=='H')?-1:-2);
                if (s[j-1]=='H'){
                    x = i;
                    y = j;
                }
            }
        }
        Q.push({x,y,0});
        mp[x][y] = 0;
        while (!Q.empty()){
            haha now = Q.front();
            Q.pop();
            for (int k=0;k<4;k++){
                if (mp[now.x+dx[k]][now.y+dy[k]]==-1){
                    mp[now.x+dx[k]][now.y+dy[k]] = now.st + 1;
                    Q.push({now.x+dx[k],now.y+dy[k],now.st+1});
                }
            }
        }
        int k,ok = 0,idx,xx,yy;
        cin >> k;
        for (int i=0;i<k;i++){
            cin >> xx >> yy;
            if (!ok && mp[xx][yy]<=i && mp[xx][yy] != -2 && mp[xx][yy] != -1){
                idx = i;
                ok = 1;
            }
        }
        if (!ok){
            cout << "NO\n";
        } else{
            cout << "YES " << idx << '\n';
        }
    }
}