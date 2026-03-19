#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int n;
    cin >> n;
    vector<int> a(n+1,0);
    vector<int> pre(n+1,0);
    for (int i=1;i<=n;i++){
        cin >> a[i];
        pre[i] = pre[i-1] + a[i];
    }
    int mi = INT_MAX;
    int ans = INT_MIN;
    for (int i=0;i<=n;i++){
        ans = max(ans,pre[i]-mi);
        mi = min(mi,pre[i]);
    }
    cout << ans << '\n';
}