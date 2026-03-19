#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
i64 a, b, n;
int main(){
    cin >> a >> b >> n;
    for(int i = n; i > 0; i --){
        if(b * i <= a){
            cout << b * i;
            return 0;
        }
    }
}