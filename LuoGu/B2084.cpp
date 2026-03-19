#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
typedef double llf;
bool is_prime(i64 num);
i64 n,i,j;
int main(){
    cin >> n;
    for(i = n;i>=1;i--){
        if(is_prime(i)&&n%i==0&&is_prime(n/i)){
            cout << i << endl;
            break;
        }
    }
    // return 0;
}
bool is_prime(i64 num){
    if(num == 2)return true;
    for(j=2;j<=sqrt(num);j++){
        if(num%j==0)return false;
    }
    return true;
}