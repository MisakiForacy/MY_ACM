#include <bits/stdc++.h>
#define endl '\n'
#define N (i64)(2e6+10)
using namespace std;
typedef long long i64;
i64 n,m,i,j,a[N],x;
void solve();
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    solve();
    return 0;
}
void solve(){
    cin >> n >> m;
    for(i = 1; i <= n; i ++)cin >> a[i];
    while(m--){
        cin >> x;
        cout << a[x] << endl;
    }
}