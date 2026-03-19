// 模拟每层的结点
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long i64;
i64 t,a,b,c,i,j,cnt,tot,res;
void solve();
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
void solve(){
    cin >> a >> b >> c;
    if(a + 1 != c){
        cout << -1 << endl;
        return;
    }
    else{
        res = 0, cnt = 1, tot = 0;
        while(a != 0 || b != 0){
            res ++, tot = 0;
            if(a >= cnt){
                a -= cnt;
                tot += cnt * 2;
                cnt = 0;
            }
            if(a < cnt){
                cnt -= a;
                tot += a * 2;
                a = 0;
            }
            if(b >= cnt){
                b -= cnt;
                tot += cnt;
                cnt = 0;
            }
            if(b < cnt){
                cnt -= b;
                tot += b;
                b = 0;
            }
            cnt = tot;
        }
        cout << res << endl;
        return;
    }
}