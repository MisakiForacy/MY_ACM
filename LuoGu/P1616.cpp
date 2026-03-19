#include <bits/stdc++.h>
#define endl '\n'
#define N (i64)(1e7+10)
using namespace std;
typedef long long i64;
i64 f[N];
i64 n,m,a,b,i,j;
int main(){
    cin >> n >> m;
    for(i=1;i<=m;i++){
        cin >> a >> b;
        for(j=a;j<=n;j++){
            f[j] = max(f[j], f[j-a]+b);
            // else f[i][j] = f[i-1][j];
        }
    }
    cout << f[n] << endl;
    return 0;
}