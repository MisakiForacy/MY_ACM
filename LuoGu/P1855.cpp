#include <bits/stdc++.h>
#define N 205
using namespace std;
typedef long long i64;
i64 f[N][N];
i64 n,m,k,i,j,s,x,y;
int main(){
    cin >> n >> m >> k;
    for(i=1;i<=n;i++){
        cin >> x >> y;
        for(j=m;j>=x;j--){
            for(s=k;s>=y;s--){
                f[j][s] = max(f[j][s],f[j-x][s-y]+1);
            }
        }
    }
    cout << f[m][k] << endl;
    return 0;
}