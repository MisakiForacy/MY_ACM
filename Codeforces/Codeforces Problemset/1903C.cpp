#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        vector<LL> a(n+1,0), suf(n+2,0);
        for (int i=1;i<=n;i++) cin >> a[i];
        for (int i=n;i>=1;i--){
            suf[i] = suf[i+1] + a[i];
        }
        int k = 1;
        LL ans = 0;
        LL sum = 0;
        for (int i=1;i<=n;i++){
            sum += a[i];
            if (suf[i+1]>0 || i==n){
                ans += k * sum;
                k ++;
                sum = 0;
            }
        }
        cout << ans << '\n';
    }
}