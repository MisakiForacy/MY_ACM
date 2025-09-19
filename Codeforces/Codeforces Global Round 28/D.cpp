#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long LL;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        int n,m;
        cin >> n >> m;
        vector<int> a(n),b(m),c(m);
        for (int i=0;i<n;i++) cin >> a[i];
        for (int i=0;i<m;i++) cin >> b[i];
        int k = a[0];
        sort(all(a));
        for (int i=0;i<m;i++){
            if (k >= b[i]){
                c[i] = 1;
            } else{
                int id = lower_bound(all(a),b[i]) - a.begin();
                c[i] = n - id + 1;
            }
        }
        c.push_back(0);
        sort(all(c));
        for (int i=1;i<=m;i++){
            LL ans = 0;
            for (int j=i;j<=m;j+=i){
                ans += c[j];
            }
            cout << ans << " \n"[i==m];
        }
    }
}