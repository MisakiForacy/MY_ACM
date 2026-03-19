#include <bits/stdc++.h>
using namespace std;
using LL = long long;
LL qpower(LL a,LL k,LL p){
    LL res = 1;
    while (k){
        if (k&1) res = res * a % p;
        a = a * a % p;
        k >>= 1;
    }
    return res;
}
int main(){
    int n,k,m,q,x;
    cin >> n >> k >> m >> q;
    vector<int> d(n+1,0);
    for (int i=0;i<m;i++){
        cin >> x;
        for (int j=1;j<=k;j++){
            d[qpower(x,j,n)] = 1;
        }
    }
    for (int i=0;i<q;i++){
        cin >> x;
        int ok = 1;
        for (int j=1;j<=k;j++){
            if (!d[qpower(x,j,n)]){
                ok = 0;
                break;
            }
        }
        cout << ok << " \n"[i==q-1];
    }
}