#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        vector<ll> a(n);
        for (int i=0;i<n;i++) cin >> a[i];
        ll sum = 0;
        ll mi = LLONG_MAX,mx = LLONG_MIN;
        for (int i=0;i<n;i++){
            sum += a[i];
            mi = min(mi,sum / (i+1));
        }
        sum = 0;
        for (int i=n-1;i>=0;i--){
            sum += a[i];
            mx = max(mx,(sum + (n-i-1)) / (n-i));
        }
        cout << mx - mi << '\n';
    }
}