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
        LL n,m,k;
        LL Min_a, Min_b, Max_a, Max_b, ans;
        ans = 0;
        Min_a = Min_b = LLONG_MAX;
        Max_b = Max_a = LLONG_MIN;
        cin >> n >> m >> k;
        vector<LL> a(n + 1);
        vector<LL> b(m + 1);
        for (int i = 1;i <= n;i ++){
            cin >> a[i];
            Min_a = min(Min_a, a[i]);
            Max_a = max(Max_a, a[i]);
        }
        for (int i = 1;i <= m;i ++){
            cin >> b[i];
            Min_b = min(Min_b, b[i]);
            Max_b = max(Max_b, b[i]);
        }
        for (int i = 1;i <= n;i ++) ans += a[i];
        if (k & 1){
            if (Max_b > Min_a){
                ans = ans - Min_a + Max_b;
            }
            cout << ans << '\n';
        } else{
            if (Max_b > Min_a){
                ans = ans - Min_a + Max_b;
                Max_a = max(Max_a,Max_b);
                Min_b = min(Min_b,Min_a);
            }
            if (Max_a > Min_b){
                ans = ans - Max_a + Min_b;
            }
            cout << ans << '\n';
        }
    }
}