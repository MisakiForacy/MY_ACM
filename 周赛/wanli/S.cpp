#include <bits/stdc++.h>
using namespace std;
const string wanli = "wanli";
const int dx[] = {-1,0,1,0};
const int dy[] = {0,1,0,-1};
static inline void print(vector<vector<char>>matrix,int n){
    for(int i=1;i<=n;i++){
        cout << matrix[i][1];
        for(int j=2;j<=n;j++){
            cout << " " << matrix[i][j];
        }
        cout << endl;
    }
}
int main(){
    int n,nn,k,x,y;
    cin >> n;
    vector<vector<char>>matrix(n+2,vector<char>(n+2,' '));
    k = 0, nn = 1;
    y = 1, x = n;
    matrix[y][x] = 'w';
    while(nn<n*n){
        if(matrix[y+dy[k]][x+dx[k]]==' ' && (1<=y+dy[k]&&y+dy[k]<=n && 1<=x+dx[k]&&x+dx[k]<=n)){
            y = y + dy[k], x = x + dx[k];
            matrix[y][x] = wanli[nn%5];
            nn++;
        }
        else{
            k++;
            k = k % 4;
        }
        // print(matrix,n);
        // cout << y << " " << x << " " << dy[k] << " " << dx[k] << endl;
    }
    print(matrix,n);
    return 0;
}