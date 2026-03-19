#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    if (s.length()<3){
        cout << "No\n";
    } else{
        int len = s.length();
        if (s[len-3]=='s' && s[len-2]=='a' && s[len-1]=='n'){
            cout << "Yes\n";
        } else{
            cout << "No\n";
        }
    }
}