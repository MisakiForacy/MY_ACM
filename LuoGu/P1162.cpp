#include <bits/stdc++.h>
#define N 35
using namespace std;
typedef long long i64;
i64 n,i,j,matrix[N][N],ss[N][N];
const i64 dx[] = {0,1,0,-1};
const i64 dy[] = {-1,0,1,0};
void dfs(i64 y,i64 x);
int main(){
    cin >> n;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            cin >> matrix[i][j];
            ss[i][j] = matrix[i][j];
        }
    }
    dfs(0,0);
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(ss[i][j])cout << matrix[i][j] << " ";
            else cout << 2 << " ";
        }
        cout << endl;
    }
    return 0;
}
void dfs(i64 y,i64 x){
    ss[y][x] = 1;
    for(int k=0;k<4;k++){
        if(!ss[y+dy[k]][x+dx[k]]&&0<=y+dy[k]&&y+dy[k]<=n+1&&0<=x+dx[k]&&x+dx[k]<=n+1)
            dfs(y + dy[k], x + dx[k]);
    }
}