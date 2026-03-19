#include <bits/stdc++.h>
#define N 35
using namespace std;
typedef long long i64;
i64 n, m, t, sx, sy, fx, fy, zx, zy;
const i64 dx[] = {0,1,0,-1};
const i64 dy[] = {-1,0,1,0};
vector<vector<i64>>matrix;
i64 cut[N][N];
void solve();
i64 dfs(i64 y, i64 x);
int main(){
    solve();
    return 0;
}
void solve(){
    cin >> n >> m >> t;
    cin >> sx >> sy >> fx >> fy;
    matrix.resize(n + 2, vector<i64>(m + 2, 1));
    for(int i = 0; i < m + 2; i ++)
        matrix[0][i] = matrix[n + 1][i] = 0;
    for(int i = 0; i < n + 2; i ++)
        matrix[i][0] = matrix[i][m + 1] = 0;
    for(int i = 0; i < t; i ++){
        cin >> zx >> zy;
        matrix[zy][zx] = 0;
    }
    cout << dfs(sy, sx) << endl;
    return;
}
i64 dfs(i64 y, i64 x){
    // if(cut[y][x])return cut[y][x];
    if(y == fy && x == fx)return 1;
    i64 tot = 0;
    matrix[y][x] = 0;
    for(int i = 0; i < 4; i ++){
        if(matrix[y + dy[i]][x + dx[i]]){
            tot += dfs(y + dy[i], x + dx[i]);
            cut[y + dy[i]][x + dx[i]] = tot;
            matrix[y + dy[i]][x + dx[i]] = 1;
        }
    }
    return tot;
}