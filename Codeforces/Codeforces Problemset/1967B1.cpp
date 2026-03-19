#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        ll n,m;
        ll cnt = 0;
        cin >> n >> m;
        for (ll b=2;b<=m;b++){
            if (b*(b-1)<=n){
                cnt += (n-b*(b-1)) / (b*b) + 1;
            }
            else break;
        }
        cout << cnt+n << '\n';
    }
}