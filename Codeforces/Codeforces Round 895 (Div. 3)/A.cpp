#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define debug(x) cerr << #x << ':' << x << ' '
using namespace std;
using LL = long long;
const LL inf = LLONG_MAX;

int main(){
    int T = 1;
    cin >> T;
    while (T --){
        int a,b,c;
        cin >> a >> b >> c;
        int d = (max(a,b) - min(a,b) + 1) / 2;
        cout << (d + c - 1) / c << '\n';
    }
}