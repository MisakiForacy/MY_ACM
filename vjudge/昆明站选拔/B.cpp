#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int n;
    cin >> n;
    vector<int> a(n+1,0);
    vector<int> pre(n+1,0);
    for (int i=1;i<=n;i++) cin >> a[i];
    sort(a.begin(),a.end());
    for (int i=1;i<=n;i++){
        pre[i] = pre[i-1] + a[i];
    }
    int ans = 0;
    for (int i=n;i>=0;i--){
        if (pre[n]-pre[i] >= pre[i]-pre[0]){
            ans = i;
            break;
        }
    }
    cout << ans << '\n';
}

// 1 1 1 1 2
// 1 2 3 4 6