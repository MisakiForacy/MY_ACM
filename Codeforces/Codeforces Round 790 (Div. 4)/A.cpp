#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define debug(x) cerr << #x << ':' << x << ' '
using namespace std;
using LL = long long;
const LL inf = LLONG_MAX;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --){
        string s;
        cin >> s;
        cout << ((s[0]-'0')+(s[1]-'0')+(s[2]-'0') == (s[3]-'0')+(s[4]-'0')+(s[5]-'0') ? "YES\n" : "NO\n");       
    }
}