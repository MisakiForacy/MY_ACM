#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    LL ans = 1;
    for (int i=2;i<=26;i++) ans *= i;
    cout << ans << '\n';
}