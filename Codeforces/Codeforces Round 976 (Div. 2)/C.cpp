#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int T;
    cin >> T;
    while (T--){
        LL b,c,d;
        cin >> b >> c >> d;
        LL lb=0, lc=0, ld=0;
        while (b >> lb) lb ++;
        while (c >> lc) lc ++;
        while (d >> ld) ld ++;
        LL len = max({lb,lc,ld});
        LL ans = 0;
        int x = 0;
        for (int i=0;i<len;i++){
            int bb,cc,dd;
            bb = (b >> i) & 1;
            cc = (c >> i) & 1;
            dd = (d >> i) & 1;
            if (bb && x){
                bb = 0, x = 0;
            } else if (!bb && x){
                bb = 1;
            }
            if (!bb && !cc && dd){
                ans += (1LL << i);
            } else if (bb && cc && !dd){
                ans += (1LL << i);
            } else if (!bb && cc && dd){
                x = 1;
            }
        }
        if ((ans|b)-(ans&c)==d){
            cout << ans << '\n';
        } else{
            cout << -1 << '\n';
        }
    }
}