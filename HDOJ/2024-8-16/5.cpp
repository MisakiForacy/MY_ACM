#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        ll k,x,y;
        cin >> k >> x >> y;
        int a1 = 1, a2 = 1;
        if (y >= k && x >= k){
            a1 = 1,a2 = 0;
        }
        cout << (a1?"Yes\n":"No\n") << (a2?"Yes\n":"No\n");
    }
}