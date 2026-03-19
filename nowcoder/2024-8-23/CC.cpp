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
                mp[i][j] = 1;
                ed.x = j, ed.y = i;
            }
        }
    }
    map<int,int> st_x,st_y;
    map<int,int> ed_x,ed_y;
    queue<haha> st_q,ed_q;
    st_q.push({st.x,st.y}), ed_q.push({ed.x,ed.y});
    mp[st.y][st.x] = 0, mp[ed.y][ed.x] = 0;
    st_x[st.x] ++, st_y[st.y] ++;
    ed_x[ed.x] ++, ed_y[ed.y] ++;
    haha st_nd, ed_nd;
    while (!st_q.empty() || !ed_q.empty()){
        int st_ok = 0, ed_ok = 0;
        if (!st_q.empty()) st_nd = st_q.front(), st_q.pop(), st_ok = 1;
        if (!ed_q.empty()) ed_nd = ed_q.front(), ed_q.pop(), ed_ok = 1;
        for (int k=0;k<4;k++){
            if (st_ok && mp[st_nd.y+dy[k]][st_nd.x+dx[k]]){
                st_q.push({st_nd.x+dx[k],st_nd.y+dy[k]});
                st_x[st_nd.x+dx[k]] ++, st_y[st_nd.y+dy[k]] ++;
                mp[st_nd.y+dy[k]][st_nd.x+dx[k]] = 0;
            }
            if (ed_ok && mp[ed_nd.y+dy[k]][ed_nd.x+dx[k]]){
                ed_q.push({ed_nd.x+dx[k],ed_nd.y+dy[k]});
                ed_x[ed_nd.x+dx[k]] ++, ed_y[ed_nd.y+dy[k]] ++;
                mp[ed_nd.y+dy[k]][ed_nd.x+dx[k]] = 0;
            }
        }
    }
    int ok = 0;
    for (auto [x1,v1]:st_x){
        for (auto [x2,v2]:ed_x){
            if (x1==x2 || x1==x2-1 || x1==x2+1){
                ok = 1;
            }
        }
    }
    for (auto [y1,v1]:st_y){
        for (auto [y2,v2]:ed_y){
            if (y1==y2 || y1==y2-1 || y1==y2+1){
                ok = 1;
            }
        }
    }
    cout << (ok?"YES\n":"NO\n");
}