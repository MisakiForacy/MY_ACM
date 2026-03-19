#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 3e6+10;
int ct[N];
int tr[N][80];
int cnt = 0;
int nxt = 0;
void solve(){
    int n,m;
    cin >> n >> m;
    string s;
    for (int i=0;i<n;i++){
        cin >> s;
        int p = 0;
        for (int j=0;j<s.length();j++){
            if (!tr[p].son[s[j]-'0']) nxt = ++cnt, ct[];
            else nxt = tr[p].son[s[j]-'0'];
            tr[p].son[s[j]-'0'] = nxt;
            ct[nxt] ++;
            p = nxt;
        }
    }
    for (int i=0;i<m;i++){
        cin >> s;
        int ans = n;
        int p = 0;
        for (int j=0;j<s.length();j++){
            p = tr[p].son[s[j]-'0'];
            ans = min(ans,ct[p]);
            if (ans == 0) break;
        }
        cout << ans << '\n';
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--){
        solve();
    }
}