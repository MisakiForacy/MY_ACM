#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    LL n,x;
    cin >> n;
    LL ans = 0;
    for (int i=0;i<n;i++){
        cin >> x;
        for (int i = 2; i * i <= x; i++){
            int cnt = 0;
            while (x % i == 0){
                x /= i;
                cnt ++;
            }
            ans ^= cnt;
        }
        if (x != 1){
            ans ^= 1;
        }
    }
    cout << (ans ? "Alice\n":"Bob\n");
}