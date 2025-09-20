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
        int n;
        string s;
        cin >> n >> s;
        map<char,int> mp;
        LL ans = 0;
        for (int i = 0;i < n;i ++){
            if (!mp.count(s[i])){
                ans += n - i;
                mp[s[i]] = 1;
            }
        }       
        cout << ans << '\n';
    }
}