#include<bits/stdc++.h>
#define For(i, n, m) for(ll i = n; i <= m; ++i)
#define endl '\n'
using namespace std;
typedef long long ll;
ll n;
int main () {
    cin >> n;
    cout << fixed << setprecision (9) << (long double) 1.00 / (n * ((n + 1) / 2) * ((n + 2) / 2));
}