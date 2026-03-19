#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int n;
    cin >> n;
    vector<int> a(n+1,0);
    vector<int> pre(n+1,0);
    vector<int> suf(n+1,0);
    for (int i=1;i<=n;i++){
        cin >> a[i];
        if (a[i] == 1){
            suf[i] += 1;
        } else{
            pre[i] += 1;
        }
    }
    for (int i=1;i<=n;i++){
        pre[i] += pre[i-1];
        suf[i] += suf[i-1];
    }
    int ans = INT_MAX;
    for (int i=0;i<=n;i++){
        ans = min(ans,pre[i]-pre[0]+suf[n]-suf[i]);
    }
    cout << ans << '\n';
}