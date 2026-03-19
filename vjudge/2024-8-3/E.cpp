#include <bits/stdc++.h>
using namespace std;
int main(){
    int up,lo;
    up = lo = 0;
    string s;
    cin >> s;
    for (int i=0;i<s.length();i++){
        if (isupper(s[i])) up ++;
        else lo ++;
    }
    if (up > lo){
        for (int i=0;i<s.length();i++){
            cout << char(toupper(s[i]));
        }
    } else{
        for (int i=0;i<s.length();i++){
            cout << char(tolower(s[i]));
        }
    }
}