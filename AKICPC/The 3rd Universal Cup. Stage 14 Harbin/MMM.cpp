#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        LL ans = 0;
        vector<LL> f(n+1,0);
        for (int i=1;i<=n;i++){
            if (n%i==0){
                f[i] = n / i;
            } else{
                f[i] = f[i-1];
            }
            ans += f[i];
        }
        cout << ans << '\n';
    }
}