#include <bits/stdc++.h>
#define N (i64)(1e6+10)
#define endl '\n'
using namespace std;
typedef long long i64;
i64 t,n,x,i,d;
void solve();
int main(){
    cin >> t;
    while(t--){
        solve();
    }
}
void solve(){
    cin >> n;
    cin >> x;
    cout << N << " " << x + N << " ";
    d = x + N;
    for(i = 0; i < n-2;i ++){
        cin >> x;
        d = d + x;
        cout << d << " ";
    }
    cout << endl;
}