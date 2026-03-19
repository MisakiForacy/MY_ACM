#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int T;
    cin >> T;
    while (T--){
        LL n;
        cin >> n;
        vector<LL> a;
        for (int i=1;i<sqrt(n);i++){
            if (!(n%i)){
                a.push_back(i);
                a.push_back(n/i);
            }
        }
        if (sqrt(n) == int(sqrt(n))){
            a.push_back(sqrt(n));
        }
        sort(a.begin(),a.end());
        LL ans = 0;
        for (int i=1;i<a.size();i++){
            ans += (a[i] - a[i-1]) * (n/a[i-1]);
        }
        ans += 1;
        cout << ans << '\n';
    }
}
