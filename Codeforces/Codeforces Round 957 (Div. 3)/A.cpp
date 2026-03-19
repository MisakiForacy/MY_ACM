#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int T;
    cin >> T;
    while (T--){
        ll a[3];
        cin >> a[0] >> a[1] >> a[2];
        sort(a,a+3);
        for (int i=0;i<5;i++){
            a[0] ++;
            sort(a,a+3);
        }
        cout << a[0] * a[1] * a[2] << '\n';
    }
}