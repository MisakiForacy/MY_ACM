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
        vector<string> a(n);
        for (int i = 0;i < n;i ++) cin >> a[i];
        LL ans = 0;
        for (char c = 'a';c <= 'e';c ++){
            vector<int> b(n,0);
            for (int i = 0;i < n;i ++){
                for (int j = 0;j < a[i].size();j ++){
                    if (a[i][j] == c) b[i] ++;
                }
                b[i] = b[i] - (a[i].size() - b[i]);
            }
            sort(all(b), [&](int x,int y){
                return x > y;
            });
            LL len = n, sum = 0;
            for (int i = 0;i < n;i ++){
                sum += b[i];
                if (sum <= 0){
                    len = i;
                    break;
                }
            }
            ans = max(ans,len);
        }
        cout << ans << '\n';
    }
}