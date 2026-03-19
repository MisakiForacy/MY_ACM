#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n,f = 1,ans = 0,x;
        cin >> n;
        for (int i=0;i<n;i++){
            cin >> x;
            ans += f*x;
            f = -f;
        }
        cout << ans << '\n';
    }
}