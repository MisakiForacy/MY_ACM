#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        LL n,k;
        cin >> n >> k;
        vector<LL> a(n);
        LL sum = 0; // 总数
        LL Max = 0;
        for (int i=0;i<n;i++) cin >> a[i], sum += a[i], Max = max(Max,a[i]);
        for (LL i=n;i>=1;i--){
            if (max(Max,(sum+i-1)/i) * i <= sum + k){
                cout << i << '\n';
                break;
            }
        }
    }
}