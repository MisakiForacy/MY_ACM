#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    ll x,y,k;
    cin >> T;
    while (T--){
        cin >> x >> y >> k;
        while (k>=y-(x%y)){
            k -= y-(x%y);
            x += y-(x%y);
            while (x%y==0){
                x /= y;
            }
            if (x==1){
                // cout << k << ": " << x << '\n';
                k = k%(y-1);
                break;
            }
        }
        cout << x + k << '\n';
    }
}