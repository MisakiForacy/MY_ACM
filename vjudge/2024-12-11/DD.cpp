#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int f(int n){
    int cnt = 0;
    for (int i=1;i<=n;i++){
        if (n%i == 0){
            cnt ++;
        }
    }
    return cnt;
}
int main(){
    int n;
    cin >> n;
    int cnt = 0;
    for (int i=1;i<=n;i++){
        if (f(i) == 9){
            cnt ++;
            cout << i << '\n';
        }
    }
    cout << cnt << '\n';
}