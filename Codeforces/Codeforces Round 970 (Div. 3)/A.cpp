#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    while (T--){
        int a,b;
        cin >> a >> b;
        if (b&1){
            b --;
            a -= 2;
        }
        cout << (((a>=0)&&(a%2==0))?"YES\n":"NO\n");
    }
}