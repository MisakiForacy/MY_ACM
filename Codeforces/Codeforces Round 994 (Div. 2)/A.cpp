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
        for (int i=0;i<n;i++) cin >> a[i];
        int ans = 0;
        int ok = 1;
        for (int i=0;i<n;i++){
            if (a[i] == 0){
                ok = 0;
                int l,r;
                l = r = 0;
                for (int j=i;j>=0;j--){
                    if (a[j] != 0){
                        l = 1;
                        break;
                    }
                }
                for (int j=i;j<n;j++){
                    if (a[j] != 0){
                        r = 1;
                        break;
                    }
                }
                if (l && r){
                    ans = max(2,ans);
                }
                if (l || r){
                    ans = max(1,ans);
                }
            }
        }
        if (ok) ans = 1;
        cout << ans << '\n';
    }
}