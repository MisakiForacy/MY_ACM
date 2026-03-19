#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    if (n >= 0){
        cout << n;
    } else{
        n = -n;
        string n1 = to_string(n), n2 = to_string(n);
        // cout << n1 << ' ' << n2 << '\n';
        n1 = n1.erase(n1.length()-1,1);
        n2 = n2.erase(n2.length()-2,1);
        // cout << n1 << ' ' << n2 << '\n';
        if (n1=="0"||n2=="0") cout << 0 << '\n';
        else if (n1 > n2){
            cout << '-' << n2 << '\n';
        } else{
            cout << '-' << n1 << '\n';
        }
    }
}