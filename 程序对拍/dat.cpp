#include <bits/stdc++.h>
// #include "testlib.h"
using namespace std;
using LL = long long;

LL random(int l,int r){
    return (rand() % (r - l + 1) + l);
}
LL R1(LL mod){
    LL ans = 2147483647;
    return ans = ans * rand() % mod + 1;
}
int main(){
    struct _timeb T;
    _ftime(&T);
    srand(T.millitm);
    int _ = 1;
    cout << _ << '\n';
    int n = random(500, 1000), k = R1(n);
    cout << n << ' ' << k << '\n';
    for (int i = 2;i <= n;i ++) {
        cout << random(1, i - 1) << ' ';
    }
}