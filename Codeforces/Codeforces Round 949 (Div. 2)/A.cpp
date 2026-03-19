#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    ll r,l,ans;
    cin >> T;
    while (T--){
        cin >> r >> l;
        ans = 1;
        while (pow(2,ans)<=l){
            ans ++;
        }
        cout << ans - 1 << '\n';
    }
}