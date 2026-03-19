#include <bits/stdc++.h>
using namespace std;
int main(){
    int l,r;
    cin >> l >> r;
    if ((l==1&&r==0) || (l==0&&r==1)){
        if (l) cout << "Yes\n";
        else cout << "No\n";
    } else{
        cout << "Invalid\n";
    }
}