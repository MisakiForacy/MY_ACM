#include <bits/stdc++.h>
using namespace std;
int t,n,a,b,c,d,ans;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t --){
        ans = 0;
        cin >> n;
        a=n/1000,b=n/100%10,c=n/10%10,d=n%10;
        a=(a==0?10:a),b=(b==0?10:b),c=(c==0?10:c),d=(d==0?10:d);
        ans = a-1+abs(b-a)+abs(c-b)+abs(d-c)+4;
        cout << ans << '\n';
    }
}