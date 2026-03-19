#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int T;
    cin >> T;
    while (T--){
        int x,y,k;
        cin >> x >> y >> k;
        cout << 0 << ' ' << 0 << ' ' << min(x,y) << ' ' << min(x,y) << '\n';
        cout << 0 << ' ' << min(x,y) << ' ' << min(x,y) << ' ' << 0 << '\n';
    }
}