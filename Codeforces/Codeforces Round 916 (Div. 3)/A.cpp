#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define debug(x) cerr << #x << ':' << x << ' '
using namespace std;
using LL = long long;

int main(){
    int T = 1;
    cin >> T;
    map<char,int> mp;
    for (char c = 'A';c <= 'Z';c ++) mp[c] = c - 'A' + 1;
    while (T --){
        int n;
        cin >> n;
        string s;
        cin >> s;
        map<char,int> p;
        for (int i = 0;i < n;i ++){
            p[s[i]] ++;
        }
        int cnt = 0;
        for (char c = 'A';c <= 'Z';c ++){
            if (p[c] >= mp[c]){
                cnt ++;
            }
        }
        cout << cnt << '\n';
    }
}