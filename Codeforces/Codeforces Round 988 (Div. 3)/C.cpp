#include <bits/stdc++.h>
#define debug(x) cerr << #x << ":" << x << '\n'
using namespace std;
using LL = long long;
bool isp(int x){
    if (x <= 2) return 1;
    for (int i=2;i*i<=x;i++){
        if (x % i == 0){
            return 0;
        }
    }
    return 1;
}
void solve(){
    int n;
    cin >> n;
    vector<int> ans;
    int ok = 0;
    for (int i=1;i<=n;i+=2) ans.push_back(i);
    for (int i=2;i<=n;i+=2) ans.push_back(i);
    int id = n / 2 + n % 2;
    for (int i=id;i<n;i++){
        if (!isp(ans[id-1]+ans[i])){
            ok = 1;
            swap(ans[id],ans[i]);
            break;
        }
    }
    if (ok){
        for (int i=0;i<n;i++){
            cout << ans[i] << " \n"[i==n-1];
        }
    } else{
        cout << -1 << '\n';
    }

    return;
}
int main(){
    int T = 1;
    cin >> T;
    while (T--){
        solve();
    }
}