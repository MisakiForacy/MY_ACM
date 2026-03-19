#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        cout << 1 << ' ';
        for (int i=1;i<n;i++){
            cout << "-1 2 ";
        }
        cout << (n-2)*2+1 << '\n';
    }
}