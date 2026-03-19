#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        ll nn = n*n%mod;
        cout << (3 * nn) / (2 * nn - 2) << '\n';
    }
}