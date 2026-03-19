#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int T;
    cin >> T;
    while (T--){
        int x,y;
        cin >> x >> y;
        int dt = max(x,y)-min(x,y);
        cout << min(x,y)*2 + dt+max(0,dt-1) << '\n';
    }
}