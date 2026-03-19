#include <bits/stdc++.h>
using namespace std;
static inline bool isprime(int num){
    int i;
    for(i=2;i<=sqrt(num);i++){
        if(!(num%i))return false;
    }
    return true;
} 
int main(){
    int n;
    int i,j,k;
    bool flag;
    cin >> n;
    for(i=4;i<=n;i+=2){
        flag = false;
        for(j=2;j<n;j++){
            if(isprime(j)&&isprime(i-j)){
                flag = true;
                break;
            }
        }
        if(flag){
            cout << i << '=' << j << '+' << (i-j) << endl;
        }
    }
}