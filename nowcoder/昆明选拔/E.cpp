#include <bits/stdc++.h>
using namespace std;
using LL = long long;
LL t0;
bool check(LL t){
    return (2+sqrt(t))*t-t*log(t)>=t0;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        cin >> t0;
        LL lo,hi;
        lo = 0, hi = 1e16;
        while (lo <= hi){
            LL t = (lo + hi) >> 1;
            if (check(t)){
                hi = t - 1;
            } else{
                lo = t + 1;
            }
            // cout << t << ' ' << lo << ' ' << hi << '\n';
        }
        cout << lo << '\n';
    }
}