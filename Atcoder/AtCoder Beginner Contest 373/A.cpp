#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    int cnt = 0;
    for (int i=1;i<=12;i++){
        cin >> s;
        if (s.length()==i){
            cnt ++;
        }
    }
    cout << cnt << '\n';
}