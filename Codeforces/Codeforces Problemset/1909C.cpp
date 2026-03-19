#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        vector<LL> L(n),R(n),C(n),D;
        for (int i=0;i<n;i++) cin >> L[i];
        for (int i=0;i<n;i++) cin >> R[i];
        for (int i=0;i<n;i++) cin >> C[i];
        sort(all(R));
        sort(all(L),[&](int x,int y){
            return x > y;
        });
        sort(all(C),[&](int x,int y){
            return x > y;
        });
        for (int i=0;i<n;i++){
            auto idx = lower_bound(all(R),L[i]);
            D.push_back(R[idx-begin(R)]-L[i]);
            R.erase(idx);
        }
        sort(all(D));
        LL ans = 0;
        for (int i=0;i<n;i++){
            ans += D[i] * C[i];
        }
        cout << ans << '\n';
    }
}