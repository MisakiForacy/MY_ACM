#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        LL x,m;
        cin >> x >> m;
        int cnt = 0;
        for (int i=1;i<=x;i++){
            LL y = x^i;
            if (y != 0 && y <= m && (x%i==0 || y%i==0)){
                cnt ++;
            }
        }
        cout << cnt << '\n';
    }
}