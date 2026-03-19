#include <bits/stdc++.h>
using namespace std;
const int dx[] = {0,1,0,-1};
const int dy[] = {-1,0,1,0};
static vector<vector<char>> matrix;
static inline void dfs(int y,int x);
int main(){
    int n,m,t=0;
    string x;
    cin >> n >> m;
    matrix.resize(n+2,vector<char>(m+2,'0'));
    for(int i=1;i<=n;i++){
        cin >> x;
        for(int j=1;j<=m;j++){
            matrix[i][j] = x[j-1];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(matrix[i][j]!='0'){
                dfs(i,j);
                t++;
            }
        }
    }
    cout << t << endl;
    return 0;
}
static inline void dfs(int y,int x){
    matrix[y][x] = '0';
    for(int i=0;i<4;i++){
        if(matrix[y+dy[i]][x+dx[i]]!='0') dfs(y+dy[i],x+dx[i]);
    }
    return;
}