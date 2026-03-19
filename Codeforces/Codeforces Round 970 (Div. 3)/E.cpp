#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;cin >> T;
    while (T--){
        int n; string s;
        cin >> n >> s; s = ' ' + s;
        if (n&1){
            int mi = n,len_odd,len_even;
            vector<vector<int>> pre_odd(26,vector<int>(n+2,0)),pre_even(26,vector<int>(n+2,0));
            for (int i=1;i<=n;i+=2) pre_odd[s[i]-'a'][i] ++;
            for (int i=2;i<=n;i+=2) pre_even[s[i]-'a'][i] ++;
            for (int i=1;i<=n;i++){
                for (int j=0;j<26;j++){
                    pre_odd[j][i] += pre_odd[j][i-1];
                    pre_even[j][i] += pre_even[j][i-1];
                }
            }
            for (int i=1;i<=n;i++){
                len_odd = len_even = 0;
                for (int j=0;j<26;j++){
                    len_odd = max(len_odd,pre_odd[j][i-1]-pre_odd[j][0]+pre_even[j][n]-pre_even[j][i]);
                    len_even = max(len_even,pre_even[j][i-1]-pre_even[j][0]+pre_odd[j][n]-pre_odd[j][i]);
                }
                mi = min(mi,n-len_even-len_odd);
            }
            cout << mi << '\n';
        } else{
            int mx_odd,mx_even;mx_even = mx_odd = 0;
            map<char,int> odd,even;
            for (int i=1;i<=n;i+=2) odd[s[i]] ++;
            for (int i=2;i<=n;i+=2) even[s[i]] ++;
            for (auto &[k,v]:odd) mx_odd = max(mx_odd,v);
            for (auto &[k,v]:even) mx_even = max(mx_even,v);
            cout << n - mx_odd - mx_even << '\n';
        }
    }
}