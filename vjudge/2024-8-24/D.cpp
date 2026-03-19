#include <bits/stdc++.h>
using namespace std;
bool isprime(int n){
    if (n < 2) return 0;
    for (int i=2;i<=sqrt(n);i++){
        if (! (n%i)) return 0;
    }
    return 1;
}
int main(){
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        cout << (isprime(n)?"Yes\n":"No\n");
    }
}