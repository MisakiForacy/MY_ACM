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
        int n,m,k;
        cin >> n >> m >> k;
        int ok = 1;
        if (n & 1){
            if (k < (m / 2)) ok = 0;
            if ((k - (m / 2)) % 2 != 0){
                if (k < 3 * (m / 2)) ok = 0;
                if ((k - 3 * (m / 2)) % 2 != 0) ok = 0;
            }
        } else if (m & 1){
            k = n * m / 2 - k;
            if (k < (n / 2)) ok = 0;
            if ((k - (n / 2)) % 2 != 0){
                if (k < 3 * (n / 2)) ok = 0;
                if ((k - 3 * (n / 2)) % 2 != 0) ok = 0;
            }
        } else{
            if (k % 2 != 0){
                if (k < 2 * (m / 2)) ok = 0;
                if ((k - 2 * (m / 2)) % 2 != 0) ok = 0;
            }
            k = n * m / 2 - k;
            if (k % 2 != 0){
                if (k < 2 * (n / 2)) ok = 0;
                if ((k - 2 * (n / 2)) % 2 != 0) ok = 0;
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}