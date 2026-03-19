#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n;
        string s;
        cin >> n;
        int ok = 0;
        for (int i=0;i<n;i++){
            cin >> s;
            int cnt = 0;
            for (int j=0;j<n;j++){
                if (s[j]=='1'){
                    cnt ++;
                }
            }
            if (cnt == 1){
                ok = 1;
            }
        }
        cout << (ok?"TRIANGLE\n":"SQUARE\n");
    }
}