// a = new Array();
// for (i = 1; i < 50; i++) a[i] = 1;
// for (i = 3; i < 50; i++) for (j = 2; j < i; j++) if (i % j == 1) a[i] += a[j];
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
int main(){
    // freopen("1.in","r",stdin);
    // freopen("1.out","w",stdout);
    int n;
    cin >> n;
    // a = new Array();
    vector<ll>a(n+1);
    for (int i = 1; i <= n; i++) a[i] = 1;
    for (int i = 3; i <= n; i++) for (int j = 2; j < i; j++) if (i % j == 1) a[i] = (a[i] + a[j]) % mod;
    for (int i = 2; i <= n; i++) cout << a[i]%mod << " \n"[i==n];
}