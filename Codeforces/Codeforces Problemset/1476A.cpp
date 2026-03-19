#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int T;
    cin >> T;
    while (T--){
        ll n,k,ans,lo = 0,hi = 1e9;
        cin >> n >> k;
        ans = 1;
        ll key = k*(n/k+!!(n%k));
        // cout << key << '\n';
        while (lo <= hi){
            ll mid = (lo+hi) / 2;
            if (n*mid >= key) hi = mid - 1;
            else lo = mid + 1;
        }
        ans = lo;
        cout << ans << '\n';
    }
}