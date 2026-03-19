#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int n;
    cin >> n;
    LL t = 0;
    LL ans = 0;
    for (int i=0;i<n;i++){
        LL x,y;
        cin >> x >> y;
        ans = max(0LL,ans-(x-t));
        ans += y;
        t = x;
    }
    cout << ans << '\n';
}