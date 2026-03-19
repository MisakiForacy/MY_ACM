#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        vector<int> a(n+2);
        int mx = 0;
        for (int i=1;i<=n;i++){
            cin >> a[i];
            mx = max(mx,a[i]);
        }
        a[0] = a[n+1] = mx+1;
        ll ans = 0;
        vector<int> stk{0};
        for (int i=1;i<=n;i++){    
            while (!stk.empty() && a[stk.back()] < a[i]){
                stk.pop_back();
            }
            ans += i - stk.back() - 1;
            stk.push_back(i);
        }
        stk.clear();
        stk.push_back(n+1);
        for (int i=n;i>=1;i--){    
            while (!stk.empty() && a[stk.back()] < a[i]){
                stk.pop_back();
            }
            if (a[stk.back()] != a[i]) ans += stk.back() - i - 1;
            stk.push_back(i);
        }
        cout << ans << '\n';
    }
}