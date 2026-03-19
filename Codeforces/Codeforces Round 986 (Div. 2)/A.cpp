#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        int n,a,b;
        int x,y;
        x = y = 0;
        cin >> n >> a >> b;
        string s;
        cin >> s;
        for (int i=0;i<=10;i++){
            s += s;
        }
        int ok = 0;
        for (int i=0;i<s.length();i++){
            if (s[i] == 'N'){
                y ++;
            } else if (s[i] == 'E'){
                x ++;
            } else if (s[i] == 'S'){
                y --;
            } else{
                x --;
            }
            if (x == a && y == b){
                ok = 1;
                break;
            }
        }
        cout << (ok ? "YES\n":"NO\n");
    }
}