#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int T;
    cin >> T;
    while (T--){
        ll n,m,ans;
        cin >> n >> m;
        ans = n;
        ans |= max(0LL,n-m);
        ans |= n+m;
        for (int i=0;i<=31;i++){
            if (max(0LL,n-m)>>(i+1)!=(n+m)>>(i+1)){
                ans |= 1LL<<i;
            }
        }
        cout << ans << '\n';
    }
}