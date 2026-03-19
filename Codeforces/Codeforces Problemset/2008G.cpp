#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        ll n,k;
        cin >> n >> k;
        vector<ll> a(n);
        for (int i=0;i<n;i++){
            cin >> a[i];
        }
        if (n!=1){
            sort(a.begin(),a.end());
            int ok = 0;
            for (int i=1;i<n;i++){
                if (__gcd(a[i-1],a[i])==1){
                    ok = 1;
                }
            }
            if (ok){
                cout << n + k - 1 << '\n';
            } else{
                ll m = a[0];
                for (int i=1;i<n;i++){
                    m = __gcd(m,a[i]);
                }
                ll mexk = k - 1;
                for (int i=0;i<n;i++){
                    a[i] = i * m;
                    if (a[i] <= mexk){
                        mexk ++;
                    }
                }
                cout << mexk << '\n';
            }
        } else{
            if (a[0]>=k){
                cout << k - 1 << '\n';
            } else{
                cout << k << '\n';
            }
        }
    }
}