#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    ll x,a,f,b;
    cin >> T;
    while (T--){
        a = 0;
        f = 1;
        cin >> x;
        string n = to_string(x);
        if (n[0]!='1'){
            f = 0;
        }
        for (int i=1;i<n.length();i++){
            if (n[i]<'5'){
                b = 5*pow(10,n.length()-1-i);
                a += b;
            } else if (n[i]=='9'){
                b = 9*pow(10,n.length()-1-i);
                a += b;
            } else{
                b = (n[i]-'0'+1)*pow(10,n.length()-1-i);
                a += b;
            }
        }
        n = to_string(x-a);
        for (int i=0;i<n.length();i++){
            if (n[i]<'5'){
                f = 0;
                break;
            }
        }
        if (f){
            cout << "YES\n";
        } else{
            cout << "NO\n";
        }
    }
}