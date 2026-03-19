#include <bits/stdc++.h>
using namespace std;
bool check(int n){
    for (int i=2;i<=sqrt(n);i++){
        if (!(n%i)) return 0;
    } return 1;
}
int main(){
    int n;
    cin >> n;
    for (int i=2;i<=n;i++){
        if (check(i) && !(n%i)){
            cout << n/i << '\n';
            break;
        }
    }
}