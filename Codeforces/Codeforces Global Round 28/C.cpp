#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
string XOR(string s1,string s2){
    reverse(s1.begin(),s1.end());
    reverse(s2.begin(),s2.end());
    for (int i=0;i<s2.size();i++){
        if (s1[i] == s2[i]){
            s1[i] = '0';
        } else{
            s1[i] = '1';
        }
    }
    reverse(s1.begin(),s1.end());
    return s1;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        string s,ts;
        cin >> s;
        ts = s;
        int n = s.length();
        pair<int,int> ans;
        string mx;
        int id = -1;
        for (int i=0;i<n;i++){
            if (s[i] == '0'){
                id = i;
                break;
            }
        }
        if (id == -1){
            cout << 1 << ' ' << 1 << ' ' << 1 << ' ' << n << '\n';
            continue;
        }
        // mx = s;
        // mx = "";
        for (int i=0;i<=id;i++){
            ts = XOR(s,s.substr(i,n-id));
            if (ts > mx){
                mx = ts;
                ans.first = i;
                ans.second = i + n - id - 1;
            }
        }
        cout << 1 << ' ' << n << ' ' << ans.first + 1 << ' ' << ans.second + 1 << '\n';
    }
}