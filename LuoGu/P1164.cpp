#include <bits/stdc++.h>
#define N 1005
using namespace std;
typedef long long i64;
i64 v[N],f[N];
i64 n,m,i,j;
int main(){
    cin >> n >> m;
    for(i=1;i<=n;i++)cin >> v[i];
    f[0] = 1;                           //剩0元的情况为1
    for(i=1;i<=n;i++){
        for(j=m;j>=v[i];j--){           //如果可以购买当前菜品
            f[j] = f[j-v[i]] + f[j];    //剩j元的情况 = 购买当前菜品后剩余的钱的情况 + 购买前剩余的钱的情况
        }
    }
    cout << f[m] << endl;
    return 0;
}