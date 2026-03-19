#include <bits/stdc++.h>
using namespace std;
const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};
static int flag;
static inline bool f(vector<vector<int>>&matrix,int y,int x){
    int i;
    if(matrix[y][x]>1)flag++;
    matrix[y][x] = 0;
    for(i=0;i<4;i++){
        if(matrix[y+dy[i]][x+dx[i]]){
            f(matrix,y+dy[i],x+dx[i]); 
        }
    }
    return flag;
}
int main(){
    int n,m;
    int i,j;
    int treasure,island;
    string str;
    treasure = 0;island = 0;
    cin >> n >> m;
    vector<vector<int>>matrix(n+2,vector<int>(m+2,0));
    for(i=1;i<=n;i++){
        cin >> str;
        for(j=0;j<m;j++){
            matrix[i][j+1] = str[j] - '0';
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(matrix[i][j]){
                flag = 0;
                island++;
                treasure += f(matrix,i,j);
            }
        }
    }
    cout << island << " " << treasure << endl;
}