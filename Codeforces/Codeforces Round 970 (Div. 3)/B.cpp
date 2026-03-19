#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n;
        string s;
        cin >> n >> s;
        s = ' ' + s;
        int ok = 1;
        if (sqrt(n)!=(int)sqrt(n)){
            ok = 0;
        } else{
            int m = sqrt(n);
            for (int i=m;i<n-m;i+=m){
                for (int j=i+2;j<i+m;j++){
                    if (s[j]=='1'){
                        ok = 0;
                    }
                }
            }
        }
        cout << (ok?"YES\n":"NO\n");
    }
}