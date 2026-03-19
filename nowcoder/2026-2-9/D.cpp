#include <bits/stdc++.h>

#define x first 
#define y second 

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())
 
using namespace std;
using LL = long long;

LL exgcd(LL a, LL b, LL &x, LL &y){
    if (!b){
        x = 1, y = 0;
        return a;
    }
    LL d = exgcd(b, a % b, y, x); // 辗转相除，并交换系数
    /*
    裴属定理：ax + by = gcd(a, b)
    拓欧
        by + (a % b)x = gcd(b, a % b)
      = by + (a - ⌊a / b⌋ * b)x
      = by + ax - ⌊a / b⌋ * b * x
      = ax + b * (y - ⌊a / b⌋ * x)
    */
    y -= a / b * x;
    return d;
}

void solve() {
    LL x, a, b;
    cin >> x >> a >> b;
    LL A = a, B = b, X, Y;
    if (x % __gcd(a, b)) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
        // exgcd(A, B, X, Y);
        // cout << X << ' ' << Y << '\n';
        LL g = __gcd(a, b);
        
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}