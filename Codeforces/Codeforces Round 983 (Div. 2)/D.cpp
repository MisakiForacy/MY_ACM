#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int ask(int u,int v){
    cout << "? " << u << ' ' << v << '\n';
    int x; cin >> x;
    return x;
}
int main(){
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        vector<int> ans(n,0);
        int fa = 1;
        for (int i=2;i<n;i++){
            if (ask(i,fa) == 0){
                ans[i] = fa;
                fa ++;
            } else{
                if (fa == 1){
                    ans[i] = 0;
                } else{
                    int ok = 1;
                    while (fa+1 != i-1){
                        fa ++;
                        if (ask(i,fa) == 0){
                            ans[i] = fa;
                            fa ++;
                            ok = 0;
                            break;
                        }
                    }
                    if (ok){
                        ans[i] = i - 1;
                        fa = i;
                    }
                }
            }
        }
        cout << "! ";
        for (int i=1;i<n;i++){
            cout << ans[i] << " \n"[i==n-1];
        }
    }
}