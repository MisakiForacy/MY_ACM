#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        if (n % 4 == 0){
            cout << "NO\n";
        } else{
            cout << "YES\n";
            vector<int> ans(32,-1);
            ans[31] = 1;
            ll nn = (n - 1) / 2;
            int cnt = 0;
            while (nn){
                if (nn&1){
                    ans[cnt] = 1;
                }
                nn >>= 1;
                cnt ++;
            }
            int ch[] = {0,-1,0,1};
            ans[0] = ch[n%4];
            for (int i=0;i<32;i++){
                cout << ans[i] << " \n"[(i+1)%8==0];
            }
        }
    }
}