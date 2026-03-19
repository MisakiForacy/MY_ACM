#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n,m,flg = 1;
        cin >> n >> m;
        vector<vector<vector<int>>>mat(3,vector<vector<int>>(n,vector<int>(m)));
        string len;
        for (int t=0;t<2;t++)
        for (int i=0;i<n;i++){
            cin >> len;
            for (int j=0;j<m;j++)
                mat[t][i][j] = len[j];
        }
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
                mat[2][i][j] = (mat[1][i][j]+3-mat[0][i][j]) % 3;
        for (int i=0;i<n;i++)
        for (int j=0;j<m;j++){
            if (mat[2][i][j]==1){
                if (j+1<m && i+1<n){
                    mat[2][i][j] = (mat[2][i][j]+2) % 3;
                    mat[2][i+1][j] = (mat[2][i+1][j]+1) % 3;
                    mat[2][i][j+1] = (mat[2][i][j+1]+1) % 3;
                    mat[2][i+1][j+1] = (mat[2][i+1][j+1]+2) % 3;
                }
            } else if (mat[2][i][j]==2){
                if (j+1<m && i+1<n){
                    mat[2][i][j] = (mat[2][i][j]+1) % 3;
                    mat[2][i+1][j] = (mat[2][i+1][j]+2) % 3;
                    mat[2][i][j+1] = (mat[2][i][j+1]+2) % 3;
                    mat[2][i+1][j+1] = (mat[2][i+1][j+1]+1) % 3;
                }
            }
        }
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
                if (mat[2][i][j])
                    flg = 0;
        cout << (flg?"YES\n":"NO\n");
    }
}