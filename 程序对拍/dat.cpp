#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())
// #include "testlib.h"
using namespace std;
using LL = long long;

mt19937_64 rnd(time(0));

LL random(int l,int r){
    return (rnd() % (r - l + 1) + l);
}

LL R1(LL mod){
    LL ans = 2147483647;
    return ans = ans * rnd() % mod + 1;
}

int main(){
    int n = 500000;
    cout << n << '\n';
    vector<LL> a(2 * n);
    for (int i = 0;i < 2 * n;i += 2) a[i] = a[i + 1] = i / 2 + 1;
    shuffle (all(a), rnd);
    for (int i = 0;i < n;i ++) cout << a[i] << ' ';
    cout << '\n';    
}