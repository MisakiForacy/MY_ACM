#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        vector<LL> a(n+1,0);
        vector<LL> pre(n+1,0);
        LL Min = INT_MAX;
        LL idx;
        for (int i=1;i<=n;i++){
            cin >> a[i];
            pre[i] = pre[i-1] + a[i];
            if (a[i] < Min){
                Min = a[i];
                idx = i;
            }
        }
        double ans1 = 1.0 * (pre[idx+1] - pre[0]) / (idx+1);
        double ans2 = 1.0 * (pre[n]-pre[idx-2]) / (n-(idx-2));
        double ans3 = 1.0 * (pre[n]-pre[0]) / n;
        // double ans4 = 1.0 * (pre[idx+1]-pre[idx-2]) / 3;
        cout << fixed << setprecision(20) << max({ans1,ans2,ans3}) << '\n';
    }
}