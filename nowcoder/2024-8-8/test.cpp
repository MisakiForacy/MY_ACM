#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,len=0;
    cin >> n;
    while (n>>=1)len++;
    cout << len+1 << '\n';
}