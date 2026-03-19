#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    while (T--) {
        ll n, k;
        cin >> n >> k;
        
        ll b = n / k;
        ll r = n % k;
        
        ll odd_count = (n + 1) / 2;
        
        if (r == 0) {
            if (odd_count % b == 0) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
        } else {
            ll L, R;
            ll L0 = odd_count - b * (k - r);
            
            if (L0 <= 0) {
                L = 0;
            } else {
                L = (L0 + b) / (b + 1);
            }
            
            R = min(r, odd_count / (b + 1));
            
            if (L > R) {
                cout << "No\n";
            } else {
                ll rem = odd_count % b;
                ll mod_val = L % b;
                ll diff = (rem - mod_val + b) % b;
                ll x0 = L + diff;
                
                if (x0 <= R) {
                    cout << "Yes\n";
                } else {
                    cout << "No\n";
                }
            }
        }
    }
    
    return 0;
}