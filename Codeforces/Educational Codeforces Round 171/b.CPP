#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        vector<LL> a(n+1,0);
        for (int i=1;i<=n;i++){
            cin >> a[i];
        }
        sort(a.begin(),a.end());
        if (n==1){
            cout << 1 << '\n';
        } else if (!(n&1)){
            LL ans = 0;
            for (int i=2;i<=n;i+=2){
                ans = max(a[i]-a[i-1],ans);
            }
            cout << ans << '\n';
        } else{
            LL ans = LLONG_MAX;
            for (int i=1;i<=n;i+=2){
                LL k = 0;
                for (int j=2;j<=n;j+=2){
                    if (j-1 == i){
                        j += 1;
                    }
                    k = max(k,a[j]-a[j-1]);
                }
                ans = min(ans,k);
            }
            cout << ans << '\n';
        }
    }
}