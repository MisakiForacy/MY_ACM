#include <bits/stdc++.h>
using namespace std;
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
        sort(a.begin(),a.end());
        int ans = abs(a[0]-a[n-1])+abs(a[0]-a[n-2])+abs(a[1]-a[n-1])+abs(a[1]-a[n-2]);
        cout << ans << '\n';
    }
}