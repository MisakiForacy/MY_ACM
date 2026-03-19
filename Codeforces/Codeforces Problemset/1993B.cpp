#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        ll n, mx_odd = -1;
        cin >> n;
        vector<ll>a(n),even;
        for (int i=0;i<n;i++){
            cin >> a[i];
            if (a[i]&1) mx_odd = max(mx_odd,a[i]);
            else even.push_back(a[i]);
        }
        if (even.size()==0||int(even.size())==n){
            cout << 0 << '\n';
        } else{
            sort(even.begin(),even.end());
            ll ans = 0, len = even.size();
            for (int i=0;i<len;i++){
                if (mx_odd > even[i]){
                    ans += 1;
                } else{
                    ans = even.size()+1;
                    break;
                }
                mx_odd += even[i];
            }
            cout << ans << '\n';
        }
    }
}