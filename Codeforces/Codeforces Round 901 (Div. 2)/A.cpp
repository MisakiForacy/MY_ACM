#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define debug(x) cerr << #x << ':' << x << ' '
using namespace std;
using LL = long long;
const LL inf = LLONG_MAX;

int main(){
    int T = 1;
    cin >> T;
    while (T --){
        LL a,b,n,x;
        cin >> a >> b >> n;
        LL ans = b - 1;
        b = 1;
        for (int i = 1;i <= n;i ++){
            cin >> x;
            ans += min(a,1 + x) - 1;
        }
        ans += 1;
        cout << ans << '\n';
    }
}