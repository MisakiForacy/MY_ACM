#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    int cnt = 0;
    int y3,y4,x3,x4;
    for (int i = 0; i <= n ; i++){
        for (int j = 0; j <= m; j++){
            cnt = -1;
            for (int ii = 0; ii <= n; ii++){
                for (int jj = 0; jj <= min(m,i+ii+j); jj++){
                    if ((j+jj+i-ii)%2 || (j+jj-i+ii)%2 || (i+ii+j-jj)%2 || (i+ii-j+jj)%2) continue;
                    y3 = j + jj + i - ii >> 1;
                    y4 = j + jj - i + ii >> 1;
                    x3 = i + ii + j - jj >> 1;
                    x4 = i + ii - j + jj >> 1;
                    if (0<=y3&&y3<=m && 0<=y4&&y4<=m && 0<=x3&&x3<=n && 0<=x4&&x4<=n){
                        cnt ++;
                    }
                }
            }
            cout << cnt << " \n"[j==m];
        }
    }
}