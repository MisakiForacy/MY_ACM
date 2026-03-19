#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n,x;
        cin >> n >> x;
        int ans = 0;
        for (int a=1;a<=x;a++){
            for (int b=1;b*a<=n&&a+b<=x;b++){
                ans += min(x-a-b,(n-a*b)/(a+b));
            }
        }
        cout << ans << '\n';
    }
}