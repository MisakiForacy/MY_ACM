#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        ll n,l,r,ans;
        cin >> n >> l >> r;
        vector<ll>ar(n+1),pre(n+1,0);
        for (int i=1;i<=n;i++){
            cin >> ar[i];
            pre[i] = pre[i-1] + ar[i];
        }
        ans = 0;
        for (int i=1;i<=n;i++){
            for (int j=i;j<=n;j++){
                if (l<=pre[j]-pre[i-1]&&pre[j]-pre[i-1]<=r){
                    i = j;
                    ans ++;
                    break;
                } else if (pre[j]-pre[i-1]>r){
                    if (j==i || ar[j]>r){
                        i = j;
                        goto t;
                    } else{
                        for (int k=i+1;k<=j;k++){
                            if (l<=pre[j]-pre[k-1]&&pre[j]-pre[k-1]<=r){
                                i = j;
                                ans ++;
                                goto t;
                            }
                        }
                    }
                }
            }
            if (pre[n]-pre[i-1]<l) break;
            t:;
        }
        cout << ans << '\n';
    }
}