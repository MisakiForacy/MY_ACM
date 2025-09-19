#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int T;
    cin >> T;
    while (T --){
        int n,x;
        cin >> n;
        map<int,int> a;
        for (int i = 1;i <= n;i ++){
            cin >> x;
            a[x % 3] ++;
        }
        cout << a[0] + min(a[1],a[2]) + (a[1] + a[2] - 2 * min(a[1],a[2])) / 3 << '\n';
    }
}