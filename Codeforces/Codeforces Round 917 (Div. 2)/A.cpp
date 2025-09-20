#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define debug(x) cerr << #x << ':' << x << ' '
using namespace std;
using LL = long long;
const LL inf = LLONG_MAX;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --){
        int n;
        cin >> n;
        vector<int> a(n + 1);
        int f,g,h;
        f = g = h = 0;
        for (int i = 1;i <= n;i ++){
            cin >> a[i];
            if (a[i] < 0) f ++;
            if (a[i] == 0) g ++;
            if (a[i] > 0) h ++;
        }
        if (g){
            cout << 0 << '\n';
        } else{
            if (f & 1){
                cout << 0 << '\n';
            } else{
                cout << 1 << '\n';
                cout << 1 << ' ' << 0 << '\n';
            }
        }
    }
}