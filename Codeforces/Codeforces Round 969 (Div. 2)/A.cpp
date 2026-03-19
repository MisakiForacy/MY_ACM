#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    while (T--){
        int l,r;
        cin >> l >> r;
        cout << ((r-l+1) + (r&1) + (l&1)) / 4 << '\n';
    }
}