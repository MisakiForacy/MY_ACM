#include <bits/stdc++.h>
#define N 1005
using namespace std;
int f[N][N];
int main(){
    int t,m,p,v;
    cin >> t >> m;
    for(int i=1;i<=m;i++){
        cin >> p >> v;
        for(int j=1;j<=t;j++){
            f[i][j] = f[i-1][j];
            if(j >= p){
                f[i][j] = max(f[i][j],f[i-1][j-p]+v);
            }
        }
    }
    cout << f[m][t] << endl;
    return 0;
}