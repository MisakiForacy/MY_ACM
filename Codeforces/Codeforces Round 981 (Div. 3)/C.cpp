#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        vector<int> a(n+2,0);
        for (int i=1;i<=n;i++){
            cin >> a[i];
        }
        for (int i=1;i<=n;i++){
            int x = (a[i]==a[i-1]) + (a[n-i+1]==a[n-i+2]);
            swap(a[i],a[n-i+1]);
            int y = (a[i]==a[i-1]) + (a[n-i+1]==a[n-i+2]);
            swap(a[i],a[n-i+1]);
            // int y = (a[i]==a[n-i]) + (a[i]==a[n-i+2]) + (a[n-i+1]==a[i-1]) + (a[n-i+1]==a[i+1]);
            if (y < x){
                swap(a[i],a[n-i+1]);
                // cout << i << '\n';
            }
        }
        int ans = 0;
        for (int i=1;i<n;i++){
            if (a[i]==a[i+1]){
                ans ++;
            }
        }
        cout << ans << '\n';
    }
}