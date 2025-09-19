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
        vector<int> a(n + 1);
        int len = 0;
        int use;
        int ans = 0;
        for (int i = 1;i <= n;i ++){
            cin >> a[i];
            use ^= a[i];
            ans = max(ans, a[i]);
        }
        int use1 = use;
        for (int i = 1;i <= n;i ++){
            use1 ^= a[i];
            ans = max(ans, (use1 ^ use));
        }
        cout << ans << '\n';
    }
}