#include <bits/stdc++.h>
#define long long int
using namespace std;
const int N = 1e5+10;
int n,a[N];
void solve(){
    cin >> n;
    int mx = 1;
    for (int i=0;i<n;i++)cin >> a[i];
    for (int i=0;i<20;i++){
        int len = 1;
        for (int j=0;j<n;j++){
            if(a[j]>>i&1){
                if (len > mx) mx = len;
                len = 1;
            } else{
                len ++;
            }
        }
        if (len > mx && len <= n) mx = len;
    }
    cout << mx << '\n';
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T --){
        solve();
    }
    return 0;
}