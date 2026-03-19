#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll T,n,x,ans;
    cin >> T;
    while (T--){
        ans = 0;
        cin >> n;
        map<ll,ll>ma;
        for (int i=0;i<n;i++){
            cin >> x;
            ans += ma[x-i];
            ma[x-i]++;
        }
        cout << ans << '\n';
    }
}