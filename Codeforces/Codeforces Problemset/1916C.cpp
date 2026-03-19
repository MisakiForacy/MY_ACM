#include <bits/stdc++.h>
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
        vector<LL> a(n+1,0);
        vector<LL> pre(n+1,0);
        vector<LL> odd(n+1,0);
        for (int i=1;i<=n;i++){
            cin >> a[i];
            pre[i] = pre[i-1] + a[i];
            odd[i] = odd[i-1] + (a[i]&1);
        }
        for (int i=1;i<=n;i++){
            if (i==1){
                cout << pre[i] << " \n"[i==n];
            } else{
                int cnt = odd[i] / 3 + (odd[i]%3==1);
                cout << pre[i] - cnt << " \n"[i==n];
            }
        }
    }
}