#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n;
        LL ans = 0;
        cin >> n;
        vector<int> a(n),b(n);
        for (int i=0;i<n;i++) cin >> a[i];
        for (int i=0;i<n;i++) cin >> b[i];
        for (int i=0;i<n-1;i++){
            if (b[i+1] < a[i]){
                ans += a[i] - b[i+1];
            }
        }
        ans += a[n-1];
        cout << ans << '\n';
    }
}