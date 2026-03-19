#include <bits/stdc++.h>
using namespace std;
int main(){
    int m[200];
    memset(m,0,sizeof(m));
    for (auto c:"codeforces"){
        m[c] = 1;
    }
    int T;
    cin >> T;
    while (T--){
        char c;
        cin >> c;
        cout << (m[c]?"YES\n":"NO\n");
    }
}