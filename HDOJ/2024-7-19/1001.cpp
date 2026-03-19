#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
const ll N = 2e6;
const ll P = 13331;
int p[N],h[N];
ull qpower(int x,int k){
    ull res = 1;
    while (k){
        if (k&1) res = x * res % mod;
        x = x * x;
        k >>= 1;
    }
    return res;
}
void init(string s){
    p[0] = 1, h[0] = 0;
    int n = s.length();
    for (int i=1;i<=n;i++){
        p[i] = p[i-1] * P;
        h[i] = h[i-1] * P + s[i];
    }
}
ull get(int lo,int hi){
    return (h[hi] - h[lo-1] * p[hi-lo+1]);
}
int main(){
    int T;
    cin >> T;
    while (T--){

    }
}