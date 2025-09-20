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
        LL n,a,b;
        cin >> n >> a >> b;
        if (a == b){
            cout << 0 << '\n';
        } else{
            LL lcm = a * b / __gcd(a,b);
            LL na = n / a - n / lcm;
            LL nb = n / b - n / lcm;
            cout << (2 * n - na + 1) * na / 2 - (1 + nb) * nb / 2 << '\n';
        }
    }
}