#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n,ok = 0;
        cin >> n;
        int len = to_string(n).length();
        for (int i=n-len*9;i<=n;i++){
            int s = 0;
            int ll = to_string(i).length();
            for (int j=0;j<ll;j++){
                s += to_string(i)[j]-'0';
            }
            if (i+s == n){
                cout << i << '\n';
                ok = 1;
                break;
            }
        }
        if (!ok){
            cout << 0 << '\n';
        }
    }
}