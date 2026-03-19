#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        LL k;
        cin >> k;
        LL lo = 0, hi = (1LL << 60);
        while (lo <= hi){
            LL mid = (lo + hi) >> 1;
            if (mid - (LL)sqrt(mid) >= k) hi = mid - 1;
            else lo = mid + 1;
        }
        cout << lo << '\n';
    }
}