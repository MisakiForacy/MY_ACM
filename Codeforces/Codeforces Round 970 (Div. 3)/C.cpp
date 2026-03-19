#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int T;
    cin >> T;
    while (T--){
        ll l,r;
        cin >> l >> r;
        ll m = sqrt((r-l)*2);
        if ((m+1)*m<=(r-l)*2){
            m ++;
        }
        cout << m << '\n';
    }
}