#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long i64;
i64 t, n;
string s;
vector<i64>factor;
void solve();
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t --){
        solve();
    }
    return 0;
}
void solve(){
    cin >> n;
    cin >> s;
    factor.clear();
    int i;
    for(int i = 1; i <= n; i ++){
        if((n % i) == 0)factor.push_back(i);
    }
    for(i = 0; i < factor.size(); i ++){
        string s1 = "", s2 = "";
        int cnt1 = 0, cnt2 = 2;
        s1 = s.substr(0,factor[i]);
        for(int j = 0; j < n; j ++){
            if(s1[j%factor[i]] != s[j])cnt1 ++;
        }
        // cout << factor[i] << endl;
        if(factor[i] != n){
            s2 = s.substr(factor[i], factor[i]);
            cnt2 = 0;
            for(int j = 0; j < n; j ++){
                if(s2[j%factor[i]] != s[j])cnt2 ++;
            }
        }
        // cout << s1 << ":" << s2 << endl;
        // cout << cnt1 << ":" << cnt2 << endl;
        if(min(cnt1,cnt2) <= 1){
            cout << factor[i] << endl;
            break;
        }
    }
}