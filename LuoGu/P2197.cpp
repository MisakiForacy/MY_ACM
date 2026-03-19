#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        int a0,a1;
        cin >> a0;
        for (int i=1;i<n;i++){
            cin >> a1;
            a0 ^= a1;
        }
        cout << (a0?"Yes\n":"No\n");
    }
}