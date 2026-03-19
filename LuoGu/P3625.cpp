#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
i64 n, m;
vector<vector<i64>>matrix;
const int dx[] = {0,1,0,-1};
const int dy[] = {-1,0,1,0};
void dfs(i64 y, i64 x);
i64 bfs(i64 y, i64 x);
int main(){
    cin >> n >> m;
    matrix.resize(n + 2, vector<i64>(m + 2));
    for(int i = 0; i <= m + 1; i ++)
        matrix[0][i] = matrix[n + 1][i] = 0;
    for(int i = 0; i <= n + 1; i ++)
        matrix[i][0] = matrix[i][m + 1] = 0;
    for(int i = 1; i <= n; i ++){
        getchar();
        for(int j = 1; j <= m; j ++){
            matrix[i][j] = (getchar() == '.');
        }
    }
    dfs(1,1);
    cout << (matrix[n][m] == 2 ? "Yes" : "No") << endl;
    return 0;
}
void dfs(i64 y, i64 x){
    matrix[y][x] = 2;
    for(int i = 0; i < 4; i ++){
        if(matrix[y + dy[i]][x + dx[i]] == 1)
            dfs(y + dy[i], x + dx[i]);
    }
}


i64 bfs(i64 y, i64 x){
    int tot = 0;
    if(y == n && x == m)return 1;
    matrix[y][x] = 0;
    for(int i = 0; i < 4; i ++){
        if(matrix[y + dy[i]][x + dx[i]]){
            tot += bfs(y + dy[i], x + dx[i]);
            matrix[y + dy[i]][x + dx[i]] = 1;
            if(tot)break;
        }
    }
    return tot;
}