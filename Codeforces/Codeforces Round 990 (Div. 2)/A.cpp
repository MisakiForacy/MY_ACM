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
        vector<int> a(n+1,0);
        vector<int> pre(n+1,0);
        for (int i=1;i<=n;i++){
            cin >> a[i];
            pre[i] = pre[i-1] + a[i];
        }
        int cnt = 0;
        for (int i=1;i<=n;i++){
            if (sqrt(pre[i]) == int(sqrt(pre[i])) && int(sqrt(pre[i]))%2==1){
                cnt ++;
            }
        }
        cout << cnt << '\n';
    }
}