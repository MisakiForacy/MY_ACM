#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int T;
    cin >> T;
    while (T--){
        LL n,k,cnt = 0;
        cin >> n >> k;
        vector<LL> a(n);
        for (int i=0;i<n;i++) cin >> a[i];
        sort(a.begin(),a.end());
        LL tot = 0;
        for (int i=0;i<n;i++){
            a[i] -= tot;
            if (a[i] * (n-i) >= k){
                cnt += k;
                break;
            } else{
                cnt += a[i] * (n-i) + 1;
                k -= a[i] * (n-i);
                tot += a[i];
            }
        }
        cout << cnt << '\n';
    }
}