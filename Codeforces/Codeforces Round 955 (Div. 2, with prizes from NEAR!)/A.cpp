#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    ll a,b,c,d;
    cin >> T;
    while (T--){
        cin >> a >> b >> c >> d;
        if ((max(a,b)==a&&max(c,d)==c)||(max(a,b)==b&&max(c,d)==d)){
            cout << "YES\n";
        } else{
            cout << "NO\n";
        }
    }
}