#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int T;
    cin >> T;
    while (T--){
        LL n,k;
        cin >> n >> k;
        if (n < 41 && (1LL << n-1) < k){
            cout << -1 << '\n';
        } else{
            vector<LL> a(n);
            iota(a.begin(),a.end(),1);
            LL lo, hi, x;
            lo = max(1LL,n-41), hi = n;
            x = max(1LL,n-41);
            LL now = lo;
            while (x <= n){
                LL y = 1LL << hi - lo - 1;
                if (k > y){
                    k = y * 2 - k + 1;
                    if (now == lo) now = hi;
                    else now = lo;
                }
                a[now-1] = x ++;
                if (now == lo){
                    now ++, lo ++;
                } else{
                    now --, hi --;
                }
            }
            for (int i=0;i<n;i++){
                cout << a[i] << " \n"[i==n-1];
            }
        }
    }
}