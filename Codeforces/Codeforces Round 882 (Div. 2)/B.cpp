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
        for (int i = 1;i <= n;i ++) cin >> a[i];
        int cnt = 0;
        LL g = (1LL << 31) - 1;
        for (int i = 1;i <= n;i ++){
            if ((g & a[i]) == 0){
                cnt ++;
                g = (1LL << 31) - 1;
            } else{
                g &= a[i];
            }
        }
        if (cnt == 0) cnt = 1;
        cout << cnt << '\n';
    }
}