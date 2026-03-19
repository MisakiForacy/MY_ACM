#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    LL n;
    cin >> n;
    LL ans = 0;
    ans += (n-3+n%3)*(n/3)/2;
    ans += (n/3+1)*(n/3);
    cout << ans << '\n';
}