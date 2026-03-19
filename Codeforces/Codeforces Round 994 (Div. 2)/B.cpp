#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        int P,S;
        S = 0, P = n;
        s = ' ' + s;
        for (int i=1;i<=n;i++){
            if (s[i] == 'p'){
                P = min(i,P);
            }
        }
        for (int i=1;i<=n;i++){
            if (s[i] == 's'){
                S = max(i,S);
            }
        }
        if (S && P){
            if (S > P){
                cout << "NO\n";
            } else{
                if (P == n){
                    cout << "YES\n";
                } else if (S == 1){
                    cout << "YES\n";
                } else{
                    cout << "NO\n";
                }
            }
        } else{
            cout << "YES\n";
        } 
    }
}