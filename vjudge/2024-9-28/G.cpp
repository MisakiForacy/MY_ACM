#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n,m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    for (int i=0;i<n;i++) cin >> a[i];
    for (int i=0;i<m;i++) cin >> b[i];
    ll ans = 0;
    for (int i=1;i<n;i++) ans += abs(a[i]-a[i-1]);
    for (int i=1;i<m;i++) ans += abs(b[i]-b[i-1]);
    cout << ans << '\n';
}