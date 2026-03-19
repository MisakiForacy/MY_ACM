#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long i64;
i64 t, a, b, c, q;
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
    if(a + 1 != c){
        cout << -1 << endl;
        return;
    }
    else{
        queue<i64>Q;
        Q.push(0);
        while(!Q.empty()){
            q = Q.front();
            Q.pop();
            if(a){
                a --;
                Q.push(q + 1);
                Q.push(q + 1);
            }
            else if(b){
                b --;
                Q.push(q + 1);
            }
        }
        cout << q << endl;
    }
}