#include <bits/stdc++.h>
using namespace std;
int main(){
    char c;
    int x;
    string s;
    cin >> x >> c;
    getchar();
    getline(cin,s);
    int len = s.length();
    if (x > len){
        for (int i=0;i<x-len;i++){
            cout << c;
        }
        cout << s << '\n';
    } else{
        for (int i=len-x;i<len;i++){
            cout << s[i];
        }
        cout << '\n';
    }
}