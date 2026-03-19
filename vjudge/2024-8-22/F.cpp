#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        cout << ((n%7==0||n%7==2)?"B\n":"A\n");
    }
}