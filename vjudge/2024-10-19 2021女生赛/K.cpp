#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int n;
    cin >> n;
    string s;
    int cnt = 0;
    getchar();
    for (int i=0;i<n;i++){
        getline(cin,s);
        for (int j=0;j<s.length();j++){
            if (s[j]=='-'){
                cnt ++;
            }
        }
    }
    cout << cnt << '\n';
}