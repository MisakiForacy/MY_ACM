#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int T;
    ll x,y,dx,dy;
    cin >> T;
    while (T--){
        cin >> x >> y;
        dx = abs(x);
        dy = y-dx+1;
        cout << (-dx<=dy?"YES\n":"NO\n");
    }
}