#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        LL tot;
        int a[200010];
        for (int i=0;i<=n;i++){
            a[i] = 0;
        }
        tot = 0;
        for (int i=0;i<n;i++){
            cin >> a[i];
            tot += a[i];
        }
        sort(a,a+n+1);
        for (int i=0;i<n;i++) cout << a[i] << " \n"[i==n-1];
        LL lo = 0, hi = 10*tot;
        while (lo <= hi){
            LL mid = lo + hi >> 1;
            double ave = 1.0 * (tot + mid) / n / 2;
            if (lower_bound(a,a+n+1,ave)-a-1 > n/2){
                hi = mid - 1;
            } else{
                lo = mid + 1;
            }
        }
        if (n <= 2){
            cout << -1 << '\n';
        } else{
            cout << lo << '\n';
        }
    }
}