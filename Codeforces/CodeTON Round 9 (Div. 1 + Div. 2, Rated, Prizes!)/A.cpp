#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        int j = 0;
        for (int i=1;i<=n;i++){
            cout << i + j << " \n"[i==n];
            j ++;
        }
    }
}