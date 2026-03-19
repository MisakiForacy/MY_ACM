#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    string s;
    while (T--){
        cin >> s;
        if (s[s.length()-1]=='?'&&s[s.length()-2]=='a'&&s[s.length()-3]=='m'){
            cout << "En!\n";
        } else{
            cout << s << '\n';
        }
    }
}