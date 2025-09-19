#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define debug(x) cerr << #x << ':' << x << ' ';
#define nl cerr << '\n';
using namespace std;
using LL = long long;
const LL inf = LLONG_MAX;
const LL MOD = 1e9 + 7;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --){
        LL n;
        cin >> n;
        if (n % 3){
            if (n / 3 + (n / 3 + 1) * 2 == n){
                cout << n / 3 << ' ' << n / 3 + 1 << '\n';
            } else{
                cout << n / 3 + 1 << ' ' << n / 3 << '\n';
            }
            
        } else{
            cout << n / 3 << ' ' << n / 3 << '\n';
        }
    }
}