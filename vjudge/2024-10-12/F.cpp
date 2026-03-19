#include <bits/stdc++.h>
using namespace std;
using LL = long long;
LL qpower(LL a,LL k){
    LL res = 1;
    while (k){
        if (k&1) res = res * a;
        a = a * a;
        k >>= 1;
    }
    return res;
}
int main(){
    int T;
    cin >> T;
    for (int t=1;t<=T;t++){
        LL n,k;
        cin >> n >> k;
        if (k==1 || k >= 30){
            cout << "Case #" << t << ": " << n << '\n';
        } else{
            LL ans = 0;
            vector<LL> seq;
            int a = 1;
            while (qpower(a,k) <= n){
                seq.push_back(qpower(a,k));
                a ++;
            }
            if (seq.back() != n){
                seq.push_back(n);
            }
            for (int i=1;i<seq.size();i++){
                ans += (seq[i] - seq[i-1] - 1) / i + 1;
            }
            cout << "Case #" << t << ": " << ans << '\n';
        }
    }
}