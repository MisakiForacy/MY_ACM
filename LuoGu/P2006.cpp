#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef unsigned long long u_i64;
bool flg = true;
u_i64 k,n,m,i,a,b;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> k >> m >> n;
    for(i=1;i<=m;i++){
        cin >> a >> b;
        if(a==0 && b>0)cout << i << " ",flg = false;
        else if(a==0 && b==0)continue;
        else if((k/a)*b>=n)cout << i << " ",flg = false;
    }
    if(flg)cout << -1 << endl;
    return 0;
}