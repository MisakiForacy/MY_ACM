#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n;
    string s;
    cin >> s >> n;
    ll len = s.length();
    ll now = len;
    while (n>len){
        now = len;
        while (now * 2 < n) now *= 2;
        n = (n - 1) % now;
        if (n==0) n = now;
    }
    cout << s[n-1] << '\n';
}