#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int dx[] = {0,1,1,1,0,-1,-1,-1};
const int dy[] = {-1,-1,0,1,1,1,0,-1};
int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> A(n+2,vector<int>(m+2,0));
    vector<vector<int>> B(n+2,vector<int>(m+2,0));
    for (int i=1;i<=n;i++){
        string s;
        cin >> s;
        for (int j=1;j<=m;j++){
            A[i][j] = s[j-1] == 'X'?-1:0;
        }
    }
    for (int i=1;i<=n;i++){
        string s;
        cin >> s;
        for (int j=1;j<=m;j++){
            B[i][j] = s[j-1] == 'X'?-1:0;
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (!A[i][j]){
                int cnt = 0;
                for (int k=0;k<8;k++){
                    cnt += (A[i+dy[k]][j+dx[k]] == -1);
                }
                A[i][j] = cnt;
            }
            if (!B[i][j]){
                int cnt = 0;
                for (int k=0;k<8;k++){
                    cnt += (B[i+dy[k]][j+dx[k]] == -1);
                }
                B[i][j] = cnt;
            }
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            cout << A[i][j] << " \n"[j==m];
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            cout << B[i][j] << " \n"[j==m];
        }
    }
}