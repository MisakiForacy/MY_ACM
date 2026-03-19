#include <bits/stdc++.h>
using namespace std;
const int dx[] = {0,1,0,-1};
const int dy[] = {-1,0,1,0};
int main(){
    int T;
    cin >> T;
    while (T--){
        int n,m,mx,nu;
        cin >> n >> m;
        vector<vector<int>>mat(n+3,vector<int>(m+3,0));
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                cin >> mat[i][j];
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                mx = 0, nu = 0;
                for (int k=0;k<4;k++){
                    if (mat[i+dy[k]][j+dx[k]]<mat[i][j]){
                        nu ++;
                        if (mat[i+dy[k]][j+dx[k]]>mx){
                            mx = mat[i+dy[k]][j+dx[k]];
                        }
                    }
                }
                if (nu == 4){
                    mat[i][j] = mx;
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                cout << mat[i][j] << " \n"[j==m];
            }
        }
    }
}