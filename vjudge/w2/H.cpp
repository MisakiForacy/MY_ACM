#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    cin >> n;
    long long ans = 0;
    for (long long i=1;i<=n;i++){
        ans += i*i;
    }
    cout << (3+n)*n << '\n' << ans << '\n';
}