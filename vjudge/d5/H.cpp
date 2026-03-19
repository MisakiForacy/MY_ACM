#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    while (T--){
        string s;
        int r,g,b,f;
        r = g = b = f = 0;
        cin >> s;
        for (int i=0;i<6;i++){
            if (s[i]=='r'){
                r = 1;
            } else if (s[i]=='g'){
                g = 1;
            } else if (s[i]=='b'){
                b = 1;
            } else if (s[i]=='R'&&!r){
                f = 1;
            } else if (s[i]=='G'&&!g){
                f = 1;
            } else if (s[i]=='B'&&!b){
                f = 1;
            }
        }
        cout << (f?"NO\n":"YES\n");
    }
}