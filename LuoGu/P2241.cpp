#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n,m,a = 0,b = 0;
    cin >> n >> m;
    for (int x=1;x<=n;x++){
        for (int y=1;y<=m;y++){
            if (x == y){
                a += (n-x+1) * (m-y+1);
            } else{
                b += (n-x+1) * (m-y+1);
            }
        }
    }
    cout << a << ' ' << b << '\n';
}