#include <bits/stdc++.h>
using namespace std;
int main(){
    char a,b,c;
    cin >> a >> b >> c;
    if (a != b && a!=c){
        cout << 'A';
    } else if (c != a && c != b){
        cout << 'C';
    } else{
        cout << 'B';
    }
}