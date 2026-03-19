#include <bits/stdc++.h>
using namespace std;
int cnt;
string s;
int main(){
    cin >> s;
    for (int i=0;i<s.length();i++)cnt += (s[i]=='1');
    cout << cnt << endl;
}