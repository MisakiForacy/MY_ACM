#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        int Mex = 0;
        for (int i=1;i<=26;i++){
            if ((n%i)){
                Mex = i;
                break;
            }
        }
        vector<char> ans(n+1,' ');
        for (char c=97;c<=122;c++){
            for (int i=c-96;i<=n;i+=Mex){
                if (ans[i]==' '){
                    ans[i] = c;
                }
            }
        }
        for (int i=1;i<=n;i++){
            cout << ans[i];
        }
        cout << '\n';
    }
}