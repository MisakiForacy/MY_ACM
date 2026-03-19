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
        for (int i=1;i<32;i++){
            ans += ((n+(1LL<<i-1)) / (1LL<<i)) * i;
        }
        cout << ans << '\n';
    }
}