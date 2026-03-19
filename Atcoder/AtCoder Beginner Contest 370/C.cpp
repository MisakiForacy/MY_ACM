#include <bits/stdc++.h>
using namespace std;
int main(){
    string s,t;
    cin >> s >> t;
    vector<string> x;
    vector<char> ls(s.length());
    for (int i=0;i<s.length();i++){
        ls[i] = s[i];
    }
    string ns;
    for (int i=0;i<s.length();i++){
        if (ls[i]>t[i]){
            ns = "";
            ls[i] = t[i];
            for (int j=0;j<s.length();j++){
                ns.push_back(ls[j]);
            }
            x.push_back(ns);
        }
    }
    for (int i=s.length()-1;i>=0;i--){
        if (ls[i]<t[i]){
            ns = "";
            ls[i] = t[i];
            for (int j=0;j<s.length();j++){
                ns.push_back(ls[j]);
            }
            x.push_back(ns);
        }
    }
    cout << x.size() << '\n';
    for (int i=0;i<x.size();i++){
        cout << x[i] << '\n';
    }
}