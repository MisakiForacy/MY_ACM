#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int T;
    cin >> T;
    while (T--){
        ll n;
        cin >> n;
        ll a = n/4;
        ll b = n%4/2;
        cout << a + b << '\n';
    }
}