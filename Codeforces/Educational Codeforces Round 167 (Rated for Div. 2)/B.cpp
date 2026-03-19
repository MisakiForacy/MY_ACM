#include <bits/stdc++.h>
using namespace std;
string a,b;
int la,lb,ans,mx,idx,mat;
void solve(){
    cin >> a >> b;
    la = a.length();
    lb = b.length();
    mx = 0;
    for (int i=0;i<lb;i++){
        mat = 0;
        idx = i;
        for (int j=0;j<la;j++){
            if (b[idx]==a[j]){
                idx ++;
                mat ++;
            }
        }
        mx = max(mx,mat);
    }
    cout << la + lb - mx << '\n';
    return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        solve();
    }
}