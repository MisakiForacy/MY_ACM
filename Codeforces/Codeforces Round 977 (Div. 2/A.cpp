#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int T;
    cin >> T;
    while (T--){
        LL n,x;
        cin >> n;
        vector<LL> a(n);
        for (int i=0;i<n;i++){
            cin >> a[i];
        }
        sort(a.begin(),a.end());
        LL ans = a[0];
        for (int i=1;i<n;i++){
            ans = ans + a[i] >> 1;
        }
        cout << ans << '\n';
    }
}