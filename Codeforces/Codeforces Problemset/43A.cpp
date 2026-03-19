#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    string s1,s2,s;
    cin >> n;
    int a,b;
    a = b = 0;
    cin >> s1;
    a ++;
    for (int i=1;i<n;i++){
        cin >> s;
        if (s==s1){
            a ++;
        } else{
            s2 = s;
            b ++;
        }
    }
    cout << (a>b?s1:s2) << '\n';
}