#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
using namespace std;
typedef long long ll;
int main(){
    int T;
    cin >> T;
    while (T--){
        ll n,m,q;
        cin >> n >> m >> q;
        vector<ll> b(m+2,0);
        for (int i=1;i<=m;i++){
            cin >> b[i];
        }
        b[m+1] = n+1;
        ll a;
        sort(all(b));
        for (int i=0;i<q;i++){
            cin >> a;
            ll l,r;
            l = *(lower_bound(all(b),a)-1);
            r = *lower_bound(all(b),a);
            // cout << l << ' ' << r << '\n';
            if (l==0){
                cout << r - 1 << '\n';
            } else if (r==n+1){
                cout << n - l << '\n';
            } else{
                cout << (r - l) / 2 << '\n';
            }
        }
    }
}