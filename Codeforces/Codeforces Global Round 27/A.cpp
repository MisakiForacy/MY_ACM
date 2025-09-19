#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int T;
    cin >> T;
    while (T--){
        LL n,m,r,c;
        cin >> n >> m >> r >> c;
        LL ans = 0;
        ans = (m - c) + m * (n-r) + (m-1) * (n-r);
        cout << ans << '\n';
    }
}