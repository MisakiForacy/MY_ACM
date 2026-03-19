#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int dx1[] = {1,-1,0,1};
const int dy1[] = {0,1,1,-1};
const int dx2[] = {1,0,-1,0};
const int dy2[] = {0,1,0,-1};
int main(){
    int n;
    while (cin >> n){
        string s;
        vector<vector<char>> mp(n+2,vector<char>(n+2));
        vector<vector<int>> vis(n+2,vector<int>(n+2,1));
        vector<vector<char>> ans(n+2,vector<char>(n+2));
        for (int i=1;i<=n;i++){
            cin >> s;
            for (int j=1;j<=n;j++){
                mp[i][j] = s[j-1];
                vis[i][j] = 0;
            }
        }
        int k = 0;
        int x,y;
        x = y = 1;
        string ns = "";
        vis[1][1] = 1;
        ns.push_back(mp[1][1]);
        for (int i=0;i<n*n-1;i++){
            while (vis[y+dy1[k]][x+dx1[k]]){
                k = (k+1) % 4;
            }
            x += dx1[k], y += dy1[k];
            vis[y][x] = 1;
            if (k==0 || k==2){
                k = (k+1) % 4;
            }
            ns.push_back(mp[y][x]);
        }
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                vis[i][j] = 0;
            }
        }
        k = 0;
        x = y = 1;
        vis[1][1] = 1;
        int t = 0;
        while (t<ns.size()-1){
            ans[y][x] = ns[t++];
            while (vis[y+dy2[k]][x+dx2[k]]){
                k = (k+1) % 4;
            }
            x += dx2[k], y += dy2[k];
            vis[y][x] = 1;
        }
        ans[y][x] = ns[t];
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                cout << ans[i][j];
            }
            cout << '\n';
        }
    }
}