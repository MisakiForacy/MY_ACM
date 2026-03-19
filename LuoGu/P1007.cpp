#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int l,n;
    int mi = INT_MAX, mx = 0;
    cin >> l >> n;
    vector<int> a(n+2,0);
    a[n] = l+1;
    for (int i=1;i<=n;i++){
        cin >> a[i];
        mi = min(mi,max(a[i-1],l-a[i]+1));
    }
    mi = min(mi,max(a[n],l-a[n+1]+1));
    mx = max(a[n],l-a[1]+1);
    if (n==0) mx = mi = 0;
    cout << mi << ' ' << mx << '\n';
}