#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n;
    cin >> n;
    vector<int>a(n);
    vector<int>b(n);
    ll A = 0, B = 0;
    for (int i=0;i<n;i++){
        cin >> a[i];
        A += a[i];
    }
    for (int i=0;i<n;i++){
        cin >> b[i];
        B += b[i];
    }
    ll ans = (A+B)/2 + ((A+B)%2?1:0);
    cout << ans << '\n';
}