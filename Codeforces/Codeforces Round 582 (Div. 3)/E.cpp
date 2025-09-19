#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using LL = long long;
bool check(string ss, string s, string t){
    if (ss.find(s) != -1 || ss.find(t) != -1) return 0;
    return 1;
}
void solve(){
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    // s = s1, t = s2;
    string ss = "abc", ans = "";
    int ok = 0;
    do{
        if (ss.find(s) == -1 && ss.find(t) == -1){
            string x = "";
            x.push_back(ss[2]);
            x.push_back(ss[0]);
            if (x != s && x != t){
                ok = 1;
                break;
            } else if (n == 1){
                ok = 1;
                break;
            }
        }
    } while (next_permutation(all(ss)));
    if (ok){
        cout << "YES\n";
        for (int i = 0;i < n;i ++){
            // cout << ss;
            ans.append(ss);
        }
    } else{
        cout << "YES\n";
        if (s[1] == t[1]){
            for (int i = 0;i < n;i ++) ans.push_back(s[1]);
            for (int i = 0;i < n;i ++) ans.push_back(s[0]);
            for (int i = 0;i < n;i ++) ans.push_back(t[0]);
        } else if (s[0] == t[0]){
            for (int i = 0;i < n;i ++) ans.push_back(s[1]);
            for (int i = 0;i < n;i ++) ans.push_back(t[1]);
            for (int i = 0;i < n;i ++) ans.push_back(s[0]);
        } else{
            char rs = 'a';
            if (s[0] == rs || t[0] == rs) rs ++;
            if (t[1] == rs || s[1] == rs) rs ++;
            for (int i = 0;i < n;i ++) ans.push_back(s[0]);
            for (int i = 0;i < n;i ++) ans.push_back(rs);
            for (int i = 0;i < n;i ++) ans.push_back(s[1]);
        }
    }
    cout << ans << '\n';
}
int main(){
    // for (char i = 'a';i <= 'c';i ++){
    //     for (char j = 'a';j <= 'c';j ++){
    //         for (char ii = 'a';ii <= 'c';ii ++){
    //             for (char jj = 'a';jj <= 'c';jj ++){
    //                 string s1, s2;
    //                 s1.push_back(i);
    //                 s1.push_back(j);
    //                 s2.push_back(ii);
    //                 s2.push_back(jj);
    //                 solve(s1, s2);
    //             }
    //         }
    //     }
    // }
    solve();
}