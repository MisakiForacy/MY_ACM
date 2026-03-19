#include <bits/stdc++.h>
using namespace std;
const int dx[] = {1,0,-1,0};
const int dy[] = {0,-1,0,1};
struct haha{
    int x,y;
};
int main(){
    int n,m;
    string line;
    cin >> n >> m;
    haha st,ed;
    vector<vector<int>> mp(n+2,vector<int>(m+2,0));
    for (int i=1;i<=n;i++){
        cin >> line;
        for (int j=1;j<=m;j++){
            mp[i][j] = (line[j-1]=='.'?1:0);
            if (line[j-1]=='S'){
                mp[i][j] = 1;
                st.x = j, st.y = i;
            } else if (line[j-1]=='E'){
                ed.x = j, ed.y = i;
            }
        }
    }
    for (int i=1;i<=n;i++) mp[i][ed.x] = 2;
    for (int i=1;i<=m;i++) mp[ed.y][i] = 2;
    int ok = 0;
    queue<haha> Q;
    Q.push({st.x,st.y});
    mp[st.y][st.x] = 0;
    while (!Q.empty()){
        haha node = Q.front();
        Q.pop();
        for (int k=0;k<4;k++){
            if (mp[node.y+dy[k]][node.x+dx[k]]){
                Q.push({node.x+dx[k],node.y+dy[k]});
                if (mp[node.y+dy[k]][node.x+dx[k]]==2){
                    ok = 1;
                }
                mp[node.y+dy[k]][node.x+dx[k]] = 0;
            }
        }
    }
    cout << (ok?"YES\n":"NO\n");
}