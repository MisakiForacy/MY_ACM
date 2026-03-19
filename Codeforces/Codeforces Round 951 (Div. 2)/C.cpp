#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 0x3f3f3f3f3f3f3f;
ll lcm(ll a,ll b){
    return (a*b) / __gcd(a,b);
}
int main(){
    ll T,n,mi,f,s,p;
    cin >> T;
    while (T --){
        f = 1,s = 0;
        mi = inf;
        cin >> n;
        vector<ll>ar(n),an(n);
        if (n!=1){
            cin >> ar[0] >> ar[1];
            p = lcm(ar[0],ar[1]);
            mi = min(ar[0],ar[1]);
            for (int i=2;i<n;i++){
                cin >> ar[i];
                if (ar[i] < mi){
                    mi = ar[i];
                }
                p = lcm(p,ar[i]);
            }
            for (int i=0;i<n;i++){
                an[i] = p/ar[i]*mi;
                s += an[i];
            }
            for (int i=0;i<n;i++){
                if (an[i]*ar[i] <= s){
                    f = 0;
                    break;
                }
            }
        } else{
            cin >> an[0];
            f = 1;
        }
        if (f){
            for (int i=0;i<n;i++){
                cout << an[i] << ' ';
            }
            cout << '\n';
        } else{
            cout << -1 << '\n';
        }
    }
}