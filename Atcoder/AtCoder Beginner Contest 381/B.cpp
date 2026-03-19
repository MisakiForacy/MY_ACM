#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    string s;
    cin >> s;
    if (s.length()%1){
        cout << "No\n";
        return 0;
    }
    string s1 = s.substr(0,s.length()/2);
    string s2 = s.substr(s.length()/2,s.length()/2);
    if (s1 == s2){
        cout << "No\n";
        return 0;
    }
    for (int i=1;i<s1.length();i++){
        if (s1[i] != s1[i-1]){
            cout << "No\n";
            return 0;
        }
    }
    for (int i=1;i<s2.length();i++){
        if (s2[i] != s2[i-1]){
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
    return 0;
}