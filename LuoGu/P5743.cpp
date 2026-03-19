#include <bits/stdc++.h>
using namespace std;
int f(int n){
    if(n==1)return 1;
    else return (f(n-1)+1)*2;
}
int main(){
    int n;
    cin >> n;
    cout << f(n) << endl;
}