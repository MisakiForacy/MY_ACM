#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<LL> a(n);
    vector<LL> pre(n),suf(n);
    for (int i=0;i<n;i++){
        cin >> a[i];
        pre[i] = a[i] - (i+1);
        suf[i] = a[i] - (n-i);
    }
    LL Max,Min;
    LL ans = -1;
    Max = LLONG_MIN;
    Min = LLONG_MAX;
    for (int i=0;i<n;i++){
        Min = min(Min,pre[i]);
        ans = max(pre[i]-Min-1,ans);
    }
    Max = LLONG_MIN;
    Min = LLONG_MAX;
    for (int i=0;i<n;i++){
        Max = max(Max,suf[i]);
        ans = max(Max-suf[i]-1,ans);
    }
    cout << ans << '\n';
}