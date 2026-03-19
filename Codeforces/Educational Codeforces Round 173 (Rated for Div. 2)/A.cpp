#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
    int T;
    cin >> T;
    while (T--){
        LL n;
        cin >> n;
        int cnt = 0;
        while (n>=4) n /= 4, cnt ++;
        cout << (1LL << cnt) << '\n';
        
    }
}