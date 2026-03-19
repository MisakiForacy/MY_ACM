#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long i64;
i64 a, b, c, t, i, j, x, ans;
queue<i64>Q;
void solve();
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t --){
        solve();
    }
    return 0;
}
void solve(){
    cin >> a >> b >> c;
    if(a != c - 1){
        cout << -1 << endl;
        return;
    }
    Q.push(0);
    while(!Q.empty()){
        x = Q.front();
        ans = x;
        Q.pop();
        if(a){
            a --;
            Q.push(x + 1);
            Q.push(x + 1);
        }
        else if(b){
            b --;
            Q.push(x + 1);
        }
    }
    cout << ans << endl;
    return;
}