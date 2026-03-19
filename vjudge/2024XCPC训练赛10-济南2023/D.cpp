#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int T;
    cin >> T;
    while (T--){
        LL la,ra,lb,rb;
        cin >> la >> ra >> lb >> rb;
        if (ra-la >= 9 || rb-lb >= 9){
            cout << 9 << '\n';
        } else{
            int ans = 0;
            for (int i=la;i<=ra;i++){
                for (int j=lb;j<=rb;j++){
                    int x = i + j;
                    while (x){
                        ans = max(ans,x%10);
                        x /= 10;
                    }
                }
            }
            cout << ans << '\n';
        }
    }
}