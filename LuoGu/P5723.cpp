#include <bits/stdc++.h>
using namespace std;
bool check(int n){
    for (int i=2;i<=sqrt(n);i++){
        if (!(n%i)) return 0;
    }
    return 1;
}
int main(){
    int n,s=0,k=2,cnt=0;
    cin >> n;
    while (1){
        if (check(k)){
            if (s+k<=n){
                s += k;
                cout << k << '\n';
                cnt ++;
            } else{
                break;
            }
        }
        if (s == n) break;
        k ++;
    }
    cout << cnt << '\n';
}