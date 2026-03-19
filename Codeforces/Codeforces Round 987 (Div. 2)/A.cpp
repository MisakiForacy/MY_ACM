#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        vector<int> a(n+1,0);
        for (int i=1;i<=n;i++){
            cin >> a[i];
        }
        int ans = INT_MAX;
        for (int i=1;i<=n;i++){
            vector<int> b(a.begin(),a.end());
            int cnt = 0;
            for (int j=i-1;j>=1;j--){
                if (b[j] > b[j+1]){
                    b[j] = b[j+1];
                    cnt ++;
                }
            }
            for (int j=i+1;j<=n;j++){
                if (b[j] < b[j-1]){
                    b[j] = b[j-1];
                    cnt ++;
                }
            }
            ans = min(ans,cnt);
        }
        cout << ans << '\n';
    }
}