#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n,t;
    cin >> n >> t;
    if (t==1){
        cout << "YES\n";
        return 0;
    }
    vector<ll>b(n),a(n+1,0);
    a[1] = 1;
    for (int i=1;i<n;i++){
        cin >> b[i];
        if (a[i]){
            a[i+b[i]] = 1;
        }
        if (a[i]&&i+b[i]==t){
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}