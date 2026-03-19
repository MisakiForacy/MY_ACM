// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
vector<vector<i64>>matrix;
vector<vector<i64>>tmp_matrix;
i64 n,m,x,y,r,z,i,j,cnt,t;
int main(){
    cin >> n >> m;
    matrix.resize(n+1,vector<i64>(n+1));
    tmp_matrix.resize(n,vector<i64>(n));
    cnt = 1;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            matrix[i][j] = cnt;
            cnt++;
        }
    }
    for(t=0;t<m;t++){
        cin >> x >> y >> r >> z;
        if(z){
            for(i=x-r;i<=x+r;i++){
                for(j=y-r;j<=y+r;j++){
                    tmp_matrix[y+r-j][i-x+r] = matrix[i][j];
                }
            }
        }
        else{
            for(i=x-r;i<=x+r;i++){
                for(j=y-r;j<=y+r;j++){
                    tmp_matrix[j-y+r][x+r-i] = matrix[i][j];
                }
            }
        }
        for(i=x-r;i<=x+r;i++){
            for(j=y-r;j<=y+r;j++){
                matrix[i][j] = tmp_matrix[i-x+r][j-y+r];
            }
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}