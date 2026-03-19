#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n,k;
        cin >> n >> k;
        if (!k){
            cout << 0 << '\n';
        } else{
            if (k <= n){
                cout << 1 << '\n';
            } else{
                k -= n;
                int cnt = 1;
                for (int i=n-1;i>=1;i--){
                    k -= i;
                    cnt ++;
                    if (k <= 0){
                        break;
                    }
                    k -= i;
                    cnt ++;
                    if (k <= 0){
                        break;
                    }
                }
                cout << cnt << '\n';
            }
        }
    }
}