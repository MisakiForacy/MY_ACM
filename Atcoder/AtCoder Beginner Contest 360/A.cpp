#include <bits/stdc++.h>
using namespace std;
int main(){
    int r,m;
    string s;
    cin >> s;
    r = m = 0;
    for (int i=0;i<3;i++){
        if (s[i]=='R'){
            r = 1;
            break;
        } else if (s[i]=='M'){
            m = 1;
        }
    }
    cout << (m?"No\n":"Yes\n");
}