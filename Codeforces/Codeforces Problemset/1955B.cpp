#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 0x3f3f3f3f3f3f3f3f;
int main(){
    int T;
    cin >> T;
    while (T--){
        ll n,c,d,x,ok = 1,mi = inf;
        cin >> n >> c >> d;
        map<ll,ll> mp;
        for (int i=0;i<n*n;i++){
            cin >> x;
            mp[x] ++;
            mi = min(mi,x);
        }
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                if (!mp[mi+i*c+j*d]) ok = 0;
                else mp[mi+i*c+j*d] --;
            }
        }
        cout << (ok?"YES\n":"NO\n");
    }
}