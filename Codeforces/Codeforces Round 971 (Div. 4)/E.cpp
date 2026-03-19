#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k;
bool check(ll x){
    return ((k+x)*(x-k+1)-(k+n+x)*(k+n-x-1)) / 2 <= 0;
}
ll f(ll x){
    return abs(((k+x)*(x-k+1)-(k+n+x)*(k+n-x-1)) / 2);
}
int main(){
    int T;
    cin >> T;
    while (T--){
        cin >> n >> k;
        ll lo = k,hi = n+k-1;
        while (lo <= hi){
            ll mid = (lo + hi) >> 1;
            if (check(mid)) lo = mid + 1;
            else hi = mid - 1;
        }
        cout << min(f(lo),f(lo-1)) << '\n';
    }
}