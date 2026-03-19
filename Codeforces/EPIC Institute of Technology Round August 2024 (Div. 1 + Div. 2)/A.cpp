#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        ll n,m,k;
        cin >> n >> m >> k;
        ll x,y;
        if (n>k) x = k;
        else x = n;
        if (m>k) y = k;
        else y = m;
        cout << x * y << '\n';
    }
}