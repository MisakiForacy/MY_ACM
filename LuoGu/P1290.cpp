#include <bits/stdc++.h>
using namespace std;
void solve(){
    int m,n,f = 1;
    cin >> m >> n;
    if (m < n) swap(m,n);
    while (m / n < 2 && m != n){
        m -= n;
        if (m < n) swap(m,n);
        f = !f;
    }
    cout << (f?"Stan wins\n":"Ollie wins\n");
}
int main(){
    int T;
    cin >> T;
    while (T--){
        solve();
    }
}