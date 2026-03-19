#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    string s;
    cin >> s;
    int d,t;
    d = t = 0;
    for (int i=0;i<s.length();i++){
        if (s[i] == 'D') d ++;
        if (s[i] == 'T') t ++;
        if (t == 3 || d == 3){
            cout << (t == 3 ? "T1":"DRX") << '\n';
            break;
        }
    }
}