#include <bits/stdc++.h>
using namespace std;
using LL = long long;
vector<int> kmp(string s,string t){
    string str = t + '\0' + s;
    vector<int> pi(str.size(),0);
    for (int i=1;i<str.size();i++){
        int len = pi[i-1];
        while (len > 0 && str[i] != str[len]){
            len = pi[len - 1];
        }
        pi[i] = len + (str[i] == str[len]);
    }
    return pi;
}
int main(){
    string s1,s2;
    cin >> s1 >> s2;
    vector<int> pi = kmp(s1,s2);
    for (int i=s2.size();i<pi.size();i++){
        if (pi[i] == s2.size()){
            cout << i - s2.size()*2 + 1 << '\n';
        }
    }
    for (int i=0;i<s2.size();i++){
        cout << pi[i] << " \n"[i==s2.size()-1];
    }
}