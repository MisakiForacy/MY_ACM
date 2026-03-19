#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    int s[4];
    for (int i=0;i<4;i++) s[i] = 0;
    cin >> a >> b;
    s[a] = s[b] = 1;
    for (int i=1;i<=3;i++){
        if (s[i]==0){
            cout << i << '\n';
            break;
        }
    }
}