#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        ll n,q,l,r,k;
        cin >> n >> q;
        vector<ll>ar(n+1,0);
        vector<ll>prefix(n+1,0);
        for (int i=1;i<=n;i++){
            cin >> ar[i];
            prefix[i] = prefix[i-1] + ar[i];
        }
        for (int i=0;i<q;i++){
            cin >> l >> r >> k;
            ll s = (l-r+1) * k + prefix[l-1] + prefix[n]-prefix[r];
            if (s&1){
                cout << "YES\n";
            } else{
                cout << "NO\n";
            }
        }
    }
}