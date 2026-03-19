#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n;
        string s;
        cin >> n;
        vector<ll>a(n+1),pre(n+1,0);
        for (int i=1;i<=n;i++){
            cin >> a[i];
            pre[i] = pre[i-1] + a[i];
        }
        cin >> s;
        int lo = 0, hi = n-1;
        ll ans = 0;
        while (lo < hi){
            if (s[lo]=='L' && s[hi]=='R'){
                ans += pre[hi+1] - pre[lo];
                lo ++, hi --;
            } else if (s[lo]=='L' && s[hi]=='L'){
                hi --;
            } else if (s[lo]=='R' && s[hi]=='R'){
                lo ++;
            } else if (s[lo]=='R' && s[hi]=='L'){
                lo ++, hi --;
            }
        }
        cout << ans << '\n';
    }
}