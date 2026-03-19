#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int T;
    cin >> T;
    while (T--){
        ll n,s = 0;
        cin >> n;
        vector<ll>ar(n+1);
        for (int i=1;i<=n;i++){
            cin >> ar[i];
            if (ar[i]>0){
                s = abs(s);
            }
            s += ar[i];
        }
        cout << abs(s) << '\n';
    }
}