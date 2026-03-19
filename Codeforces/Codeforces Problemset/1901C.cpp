#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 2e5+10;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        LL a[N];
        LL Max = LLONG_MIN;
        LL Min = LLONG_MAX;
        for (int i=1;i<=n;i++){
            cin >> a[i];
            Max = max(Max,a[i]);
            Min = min(Min,a[i]);
        }
        LL Datle = Max - Min;
        int ans = 0;
        while ((1LL << ans) <= Datle){
            ans ++;
        }
        cout << ans << '\n';
        if (ans <= n){
            for (int i=0;i<ans;i++){
                cout << Min << " \n"[i==ans-1];
            }
        }
    }
}