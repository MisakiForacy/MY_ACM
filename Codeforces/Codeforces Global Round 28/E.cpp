#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n,m;
        cin >> n >> m;
        if (2*n <= m){
            cout << "NO\n";
        } else{
            cout << "YES\n";
            int vis[2*n+1][m+1];
            memset(vis,0,sizeof(vis));
            int clo = 1;
            for (int i=1;i<=2*n;i++){
                for (int j=1;j<=m;j++){
                    if (!vis[i][j]){
                        vis[i][j] = clo;
                        cnt ++;
                    }
                }
            }
        }
    }
}