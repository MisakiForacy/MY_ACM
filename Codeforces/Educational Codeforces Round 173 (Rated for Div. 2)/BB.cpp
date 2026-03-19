#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
    int T;
    // cin >> T;
    T = 1;
    while (T--){
        for (int i=111111;i<=999999;i+=111111){
            cout << (i%9 == 0) << '\n';
        }
    }
}