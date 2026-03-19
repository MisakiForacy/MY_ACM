#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int T;
    cin >> T;
    while (T--){
        ll n,m,q;
        cin >> n >> m >> q;
        vector<ll> b(m);
        for (int i=0;i<m;i++){
            cin >> b[i];
        }
        ll a;
        sort(b.begin(),b.end());
        for (int i=0;i<q;i++){
            cin >> a;
            if (a<b[0]){
                cout << b[0] - 1 << '\n';
            } else if (a > b[0] && a < b[1]){
                cout << (b[1] - b[0]) / 2 << '\n';
            } else{
                cout << n - b[1] << '\n';
            }
        }
    }
}