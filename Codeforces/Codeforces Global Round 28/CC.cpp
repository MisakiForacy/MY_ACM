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
    int T;
    cin >> T;
    while (T--){
        string s,ts;
        cin >> s;
        ts = s;
        int n = s.length();
        pair<int,int> ans;
        string mx;
        for (int i=0;i<n;i++) mx.push_back('0');
        for (int i=0;i<n;i++){
            for (int j=i;j<n;j++){
                if (XOR(s,s.substr(i,j-i+1)) > mx){
                    mx = XOR(s,s.substr(i,j-i+1));
                    ans.first = i;
                    ans.second = j;
                }
            }
        }
        cout << 1 << ' ' << n << ' ' << ans.first + 1 << ' ' << ans.second + 1 << '\n';
    }
}