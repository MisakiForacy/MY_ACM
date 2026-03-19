#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n,r;
        cin >> n >> r;
        vector<int> a(n);
        int cnt = 0;
        int tot = 0;
        for (int i=0;i<n;i++){
            cin >> a[i];
            tot += a[i];
            cnt += a[i] % 2;
        }
        tot -= cnt;
        r -= tot/2;
        if (r > cnt){
            cout << tot + cnt << '\n';
        } else{
            cout << r * 2 - cnt + tot << '\n';
        }
    }
}