#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n,m;
        cin >> n >> m;
        ll cnt = 0;
        for (ll a=1;a<=n;a++){
            for (ll b=1;b<=m;b++){
                if ((b*__gcd(a,b))%(a+b)==0){
                    cout << a << ' ' << b << '\n';
                    cnt ++;
                }
            }
        }
        cout << cnt << '\n';
    }
}