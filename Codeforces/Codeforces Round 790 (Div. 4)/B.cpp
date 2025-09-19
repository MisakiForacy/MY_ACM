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
        int n,x;
        cin >> n;
        LL s = 0;
        vector<LL> a(n + 1);
        LL Min = inf;
        for (int i = 1;i <= n;i ++){
            cin >> a[i];
            Min = min(Min,a[i]);
        }       
        for (int i = 1;i <= n;i ++){
            s += a[i] - Min;
        }
        cout << s << '\n';
    }
}