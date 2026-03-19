#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n;
    cin >> n;
    string s = to_string(n);
    for (int i=0;i<s.length();i++){
        if (s[i]>'4'&&((i==0&&s[i]!='9')||i!=0)){
            cout << char('9'-s[i]+'0');
        } else{
            cout << s[i];
        }
    }
}