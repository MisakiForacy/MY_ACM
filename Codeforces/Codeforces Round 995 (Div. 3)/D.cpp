#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        LL n,x,y;
        cin >> n >> x >> y;
        vector<LL> a(n);
        LL sum = 0;
        for (int i=0;i<n;i++){
            cin >> a[i];
            sum += a[i];
        }
        LL l = sum - y;
        LL r = sum - x;
        LL ans = 0;
        sort(a.begin(),a.end());
        for (int i=0;i<n-1;i++){
            int ll = lower_bound(a.begin()+i+1,a.end(),l-a[i]) - a.begin();
            int rr = upper_bound(a.begin()+i+1,a.end(),r-a[i]) - a.begin() - 1;
            ans += max(0,rr-ll+1);
            // cout << 
        }
        cout << ans << '\n';
    }
}