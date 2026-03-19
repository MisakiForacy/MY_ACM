#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,mx = 0;
    cin >> n;
    vector<int> a(n);
    for (int i=0;i<n;i++) cin >> a[i];
    sort(a.begin(),a.end());
    for (int i=1;i<n;i++){
        mx = max(mx,a[i]-a[i-1]);
    }
    cout << mx << '\n';
}