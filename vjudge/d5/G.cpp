#include <bits/stdc++.h>
using namespace std;
int main(){
    int n = 1;
    string s;
    cin >> s;
    stack<char>stk;
    for (int i=0;i<s.length();i++){
        if (n==1&&s[i]=='h'){
            n ++;
        } else if (n==2&&s[i]=='e'){
            n ++;
        } else if (n==3&&s[i]=='l'){
            n ++;
        } else if (n==4&&s[i]=='l'){
            n ++;
        } else if (n==5&&s[i]=='o'){
            n ++;
        }
    }
    cout << (n==6?"YES\n":"NO\n");
}