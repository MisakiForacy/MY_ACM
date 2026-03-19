#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    LL a,b,c;
    cin >> a >> b >> c;
    LL n = 100;
    LL x = a;
    cout << n << '\n';
    for (int i=1;i<=n;i++){
        if (i > n * 0.5){
            x = b;
        }
        if (i > n * 0.95){
            x = c;
        }
        if (i > n * 0.99){
            x = 1e9;
        }
        cout << x << " \n"[i==n];
    }
}