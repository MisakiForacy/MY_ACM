#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i=0;i<n;i++){
            cin >> a[i];
        }
        ll ans = a.back();
        for (int i=0;i<n-2;i++){
            ans += a[i];
        }
        ans -= a[n-2];
        cout << ans << '\n';
    }
}