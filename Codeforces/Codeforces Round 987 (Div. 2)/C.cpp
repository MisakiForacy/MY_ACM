#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        if ((n&1) && n<27){
            cout << -1 << '\n';
        } else{
            if (!(n&1)){
                for (int i=1;i<n;i+=2){
                    cout << i/2+1 << ' ' << i/2+1 << ' ';
                }
                cout << '\n';
            } else{
                cout << "1 2 3 4 5 6 7 8 9 1 2 3 4 5 6 7 8 9 10 10 11 11 13 12 12 1 13 ";
                for (int i=28;i<n;i+=2){
                    cout << i/2 << ' ' << i/2 << ' ';
                }
                cout << '\n';
            }
        }
    }
}