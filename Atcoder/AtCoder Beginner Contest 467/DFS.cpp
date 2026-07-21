#include <bits/stdc++.h>

using namespace std;

const int N = 15;

vector<int> g[N];
vector<vector<int>> g(N);

vector<int> vis(N);

void dfs(int u) {
    vis[u] = 1;
    for (int v : g[u]) {
        if (!vis[v]) 
            dfs(v);
    }
}

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

int vis[N][N], mp[N][N];

void dfs(int x, int y) {
    vis[x][y] = 1;
    for (int k = 0;k < 4;k ++) {
        int nx = x + dx[k], ny = y + dy[k];
        if (!vis[nx][ny] && !mp[nx][ny]) {
            dfs(nx, ny);
        }
    }
}

int main() {
    
}