#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    LL n,m;
    cin >> n >> m;
    int op;
    LL x,y,k,lx,ly;
    lx = ly = n;
    for (int i=0;i<m;i++){
        cin >> op;
        if (op == 1){
            cin >> x >> y >> k;
            if (x < lx){
                lx = x;
            }
            if (y < ly){
                ly = y;
            }
        } else{
            cout << max(0LL,n * n - lx * ly) << '\n';
        }
    }
}