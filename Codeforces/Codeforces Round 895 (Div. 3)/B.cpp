#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define debug(x) cerr << #x << ':' << x << ' '
using namespace std;
using LL = long long;
const LL inf = LLONG_MAX;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --){
        int n;
        cin >> n;
        LL ans = inf;
        LL d,s;
        for (int i = 1;i <= n;i ++){
            cin >> d >> s;
            ans = min(ans,d + (s - 1) / 2);
        }       
        cout << ans << '\n';
    }
}