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
        int n;
        cin >> n;
        vector<LL> a(n + 1, inf);
        for (int i = 1;i <= n;i ++) cin >> a[i];
        int px = 1, py = 1, ok = 1, y = n;
        for (int i = 1;i <= n;i ++){
            while (a[y] < py) y --;
            if (a[px] != y){
                ok = 0;
            }
            px ++, py ++;
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}