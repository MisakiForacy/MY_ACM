#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve(){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    s = ' ' + s;
    vector<int> p(n + 1, 0);
    for (int i = 1;i <= n;i ++) p[i] = p[i - 1] + (s[i] == 'B');
    if (p[n] == k){
        cout << 0 << '\n';
    } else{
        cout << 1 << '\n';
        if (p[n] > k){
            int x;
            for (int i = 0;i <= n;i ++){
                if (p[n] - p[i] == k){
                    x = i;
                    break;
                }
            }
            cout << x << ' ' << 'A' << '\n';
        } else{
            int x;
            for (int i = 0;i <= n;i ++){
                if (p[n] - p[i] + i == k){
                    x = i;
                    break;
                }
            }
            cout << x << ' ' << 'B' << '\n';
        }
    }
}

int main(){
    int T = 1;
    cin >> T;
    while (T --) solve();
}