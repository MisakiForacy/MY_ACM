#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    LL n,m;
    cin >> n >> m;
    LL sum = 0;
    LL s,d;
    s = d = 0;
    vector<int> a(n);
    for (int i=0;i<n;i++){
        cin >> a[i];
        sum += a[i];
    }
    int ans = m;
    for (LL i=0;i<=1e7;i++){
        if (ans > (sum+i*n)%m){
            ans = (sum+i*n)%m;
            s = i;
            d = 0;
        }
    }
    sum += n*(n+1)/2;
    for (int i=0;i<=1e7;i++){
        if (ans > (sum+i*n)%m){
            ans = (sum+i*n)%m;
            s = i;
            d = 1;
        }
    }
    cout << ans << '\n';
    cout << s << ' ' << d << '\n';
}