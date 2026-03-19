#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n,k;
        cin >> n >> k;
        vector<LL> a(n+1,0);
        vector<LL> b(n+1,0);
        vector<LL> c(8*k,0);
        LL Max = LLONG_MIN;
        for (int i=1;i<=n;i++){
            cin >> a[i];
            Max = max(Max,a[i]);
        }
        for (int i=1;i<=n;i++){
            b[i] = (Max - a[i]) % (2*k);
        }
        // 4 4
        // 2 3 4 5
        // 3 2 1 0
        //   0 1 2 3 4 5 6 7 8 9 10 11
        // 3 1 0 0 0 0 1
        // 2 1 1 0 0 0
        // 1 1 1 1 0 0
        // 0 1 1 1 1 0

        // 4 3
        // 3 4 8 9
        // 0 5 1 0
        //   0 1 2 3 4 5 6 7 8 9 10 11 12
        // 0 1 1 1 0
        // 5 0 1 1 1 0
        // 1 1 1 0
        // 0 1 1 1 0
        for (int i=1;i<=n;i++){
            // int pos = b[i];
            if (b[i] >= k){
                c[b[i]-k+1] += 1;
                c[b[i]-1] -= 1;
                pos = 
            } else{
                // pos = b[i] - k;
                
            }
            for (int j=pos;j<=4*k;j+=2*k){
                c[j] -= 1;
                c[j+k+1] += 1;
            }
        }
        int ans = -1;
        for (int i=0;i<=4*k;i++){
            if (i>0) c[i] += c[i-1];
            if (c[i] == n){
                ans = Max + i;
                break;
            }
        }
        cout << ans << '\n';
    }
}