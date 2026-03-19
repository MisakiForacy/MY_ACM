#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    for (int i=n-1;i>0;i--){
        if ((n^i)==__gcd(n,i)){
            cout << i << '\n';
        }
    }
}