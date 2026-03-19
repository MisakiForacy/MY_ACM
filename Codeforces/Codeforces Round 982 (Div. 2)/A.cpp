#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int T;
    cin >> T;
    while (T--){
        LL n,x,y;
        cin >> n;
        LL mx1,mx2;
        mx1 = mx2 = 0;
        for (int i=0;i<n;i++){
            cin >> x >> y;
            mx1 = max(mx1,x);
            mx2 = max(mx2,y);
        }
        cout << (mx1+mx2) * 2 << '\n';
    }
}