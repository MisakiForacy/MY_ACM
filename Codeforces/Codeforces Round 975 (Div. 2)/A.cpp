#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        vector<ll> a(n);
        ll n1,n2;
        n1 = n2 = 0;
        for (int i=0;i<n;i++){
            cin >> a[i];
            if (i&1) n1 = max(n1,a[i]);
            else n2 = max(n2,a[i]);
        }
        cout << max(n2+(n/2+n%2),n1+(n/2)) << '\n';
    }
}